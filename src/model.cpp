#include <model.h>
#include <QtGui>
#include <math.h>
#include <fstream>
#include <iostream>
#include <string>
#include <cassert>
#include <cstdlib>
#include <string>
#include "liblinear-1.8/linear.h"

#define Malloc(type,n) (type *)malloc((n)*sizeof(type))

Model::Model()
{
    m_featuresNumber = 0;
    m_instancesNumber = 0;
    m_precision = 0.0;
    m_recall = 0.0;
    m_fScore = 0.0;
    m_dirName = ""; // dir for train/classify
    m_trueLocationFileName = ""; // test-processed.idl
    m_userLocationFileName = ""; // predicted.txt
    m_modelFileName = ""; // model.txt
    m_classifier = NULL;
}

Model::~Model()
{
    if (m_classifier)
        free_and_destroy_model(&m_classifier);
}

void Model::setTrueLocationFileName(const QString& fileName)
{
    m_trueLocationFileName = fileName;
}

void Model::setUserLocationFileName(const QString& fileName)
{
    m_userLocationFileName = fileName;
}

void Model::setModelFileName(const QString& fileName)
{
    m_modelFileName = fileName;
}

void Model::setDirName(const QString& dirName)
{
    m_dirName = dirName;
}

QString Model::getTrueLocationFileName()
{
    return m_trueLocationFileName;
}

QString Model::getUserLocationFileName()
{
    return m_userLocationFileName;
}


QString Model::getModelFileName()
{
    return m_modelFileName;
}

QString Model::getDirName()
{
    return m_dirName;
}

double Model::getPrecision()
{
    return m_precision;
}

double Model::getRecall()
{
    return m_recall;
}

double Model::getFScore()
{
    return m_fScore;
}

bool Model::saveModel()
{
    // Save model
    QByteArray ba = m_modelFileName.toLocal8Bit();
    if (save_model(ba.data(), m_classifier))
        return false;
    else
        return true;
}

bool Model::loadModel()
{
    // Load model
    QByteArray ba = m_modelFileName.toLocal8Bit();
    if ((m_classifier = load_model(ba.data())) == 0)
        return false;

    // Read number of features from model file
    QFile file(m_modelFileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;
    QTextStream in(&file);
    QString str;
    do
        in >> str;
    while (str.compare("nr_feature"));
    in >> m_featuresNumber;
    file.close();
    return true;
}

void Model::sample()
{
    /* Sample positive and negative examples for subsequent training.

       Put feature vector of i's example in m_features[i] and
       its label in m_labels[i] (+1 for positive and -1 for negative examples).

       Training image are contained in training directory(m_dirName).
    */

     const int n_feat = 2000;

     QVector<int> features(n_feat);
     QVector<QVector <int> > patch (250);

	 QString filename;
     QString path = m_dirName;

	 int go = 1;
	 while (go != 3)
	 {
		 for (int p = 0; p < 500; p++)
		 {
			 path = m_dirName;
			 if (p < 10) filename = "000" + QString::number(p);
			 else if (p < 100) filename = "00" + QString::number(p);
			 else if (p < 1000) filename = "0" + QString::number(p);

			 if (go == 1) path.append("/positive/");
				else path.append("/negative/");
			 path.append(filename);
			 path.append(".png");

			 QImage image(path);
			 HOG (image, patch);

			 for (int i = 0; i<250; i++)
				 for (int j=0; j<8; j++)
				 {
					 features [i*8 + j] = patch [i][j];
				 }
			
			 m_features.push_back(features);
			 if (go == 1) m_labels.push_back(1);
				else m_labels.push_back(-1);
		 }

		 go++;
	 }
}

void Model::trainModel()
{
    /* Training procedure.

       You can vary SVM regularization parameter C(param.C)
    */

    m_featuresNumber = m_features[0].size();
    m_instancesNumber = m_features.size();

    struct problem prob;
    prob.l = m_instancesNumber;
    prob.bias = -1;
    prob.n = m_featuresNumber;
    prob.y = Malloc(int, m_instancesNumber);
    prob.x = Malloc(struct feature_node *, m_instancesNumber);

    for (int i = 0; i < m_instancesNumber; i++)
    {
        prob.x[i] = Malloc(struct feature_node, (this->m_featuresNumber)+1);
        prob.x[i][m_featuresNumber].index = -1;
        for (int j = 0; j < m_featuresNumber; j++)
        {
            prob.x[i][j].index = j+1;
            prob.x[i][j].value = m_features[i][j];
        }
        prob.y[i] = m_labels[i];
    }

    struct parameter param;
    param.solver_type = L2R_L2LOSS_SVC_DUAL;
    param.C = 0.1;      // try to vary it
    param.eps = 1e-4;
    param.nr_weight = 0;
    param.weight_label = NULL;
    param.weight = NULL;

    m_classifier = train(&prob, &param);
    destroy_param(&param);
    free(prob.y);
    for (int i = 0; i < m_instancesNumber; i++)
        free(prob.x[i]);
    free(prob.x);
}

void Model::sampleAndTrain()
{
    m_features.clear();
    m_labels.clear();
    sample();
    trainModel();
}

QVector<int> Model::detect(const QImage &image)
{
    /* Detect objects in image using sliding window technique.

       You should return coordinates of all detected objects in QVector<int>.

       Follow instructions in code.
    */

    QVector<int> areas;

	/*
    struct feature_node* x = Malloc(struct feature_node, this->m_featuresNumber + 1);
    x[m_featuresNumber].index = -1;
    //  YOUR CODE HERE:
    //        slide with window along image and for each considering
    //        region do the following
    {
        //  YOUR CODE HERE:
        //        compute feature vector of considering region and
        //        put it in 'descriptor'
        QVector<double> descriptor;
        for (int j = 0; j < m_featuresNumber; j++)
        {
            x[j].index = j+1;
            x[j].value = descriptor[j];
        }

        double prob_estimates[1];  // level of confidence
        int predicted_label = predict_values(m_classifier, x, prob_estimates);
        //  YOUR CODE HERE:
        //        do something depending on predicted_label value
    }
    free(x);
	*/

    return areas;
}

void Model::classifyDirectory()
{
    /* Detect objects on images in directory(m_dirName).

       Write positions of detected objects in file(m_userLocationFileName)
       in form "<filename> <topLeftX> <topLeftY> <width> <height>\n".

       Use Model::detect method to find all objects in image.
    */

     const int n_feat = 2000;

     int i, j;
     int k = 0;
     FILE *resultFile;

     char buffer[30];

     double predict_max = 0;
     int x0;

     QImage image;
     QString path, filename;
     struct model* modelPedestr;

     modelPedestr = load_model(m_modelFileName.toAscii().data());

	 QString qtStrData;  
     QByteArray inBytes;  
     const char *cStrData;
     qtStrData = m_userLocationFileName;
     inBytes = qtStrData.toUtf8();  
     cStrData = inBytes.constData();
     resultFile = fopen (cStrData, "w");

	for (int p = 0; p < 50; p++)
	{
		path = m_dirName;
		if (p < 10) filename = "000" + QString::number(p);
		else if (p < 100) filename = "00" + QString::number(p);

		path.append("/");
		path.append(filename);
		path.append(".png");

        QImage image1(path);
        QVector<QVector <int> > patch (250);
        QVector<int> features(n_feat);

        while (k < (image1.width() - 81))
        {
            image = image1.copy( k, 0, 80, 200);
            HOG (image, patch);
            k = k + 8;

            for (i = 0; i<250; i++)
                for (j=0; j<8; j++)
                {
                    features [i*8 + j] = patch [i][j];
                }

        struct feature_node* x = Malloc(struct feature_node, n_feat+1);
        x[n_feat].index = -1;
        double prob_estimates[1];
        for ( j = 0; j < n_feat; j++)
        {
            x[j].index = 1+j;
            x[j].value = features[j];
        }

        int predict_label = predict(modelPedestr,x);
        predict_values(modelPedestr,x,prob_estimates);
        if (predict_label == 1)
        {
            if (predict_max < prob_estimates[0])
            {
                predict_max = prob_estimates[0];
                x0 = k;
            }
        }
        free(x);
        }

        image = image1.copy( image1.width() - 81, 0, 80, 200);
        HOG (image, patch);

        for (i = 0; i<250; i++)
            for (j=0; j<8; j++)
            {
                features [i*8 + j] = patch [i][j];
            }
        struct feature_node* x = Malloc(struct feature_node, n_feat+1);
        x[n_feat].index = -1;
        double prob_estimates[1];
        for ( j = 0; j < n_feat; j++)
        {
            x[j].index = 1+j;
            x[j].value = features[j];
        }

        int predict_label = predict(modelPedestr,x);
        predict_values(modelPedestr,x,prob_estimates);
        if (predict_label == 1)
        {
            if (predict_max < prob_estimates[0])
            {
                predict_max = prob_estimates[0];
                x0 = image1.width() - 1;
            }
        }
        free(x);
        if (x0 != -1)
        { 
			QByteArray inBytes;  
			const char *cStrData;  
			inBytes = filename.toUtf8();  
			cStrData = inBytes.constData();

			sprintf(buffer, "%s %d 0 80 200\n", cStrData, x0);
			fputs (buffer, resultFile);

        for (j = 0; j < 30; j++)
            buffer[j]='\0';
        }
    }
    free_and_destroy_model(&modelPedestr);
    fclose(resultFile);
}

bool Model::estimateQuality()
{
    /* Estimate quality of classifier

       You should compute precision, recall and F-score(2*P*R/(P+R)) and
       put these values in m_precision, m_recall and m_fScore, respectively.
       Return true if everything is OK, false - otherwise.

       You can read predicted locations from m_userLocationFileName file and
       ground truth locations from m_trueLocationFileName file.
    */

    FILE *result, *trueFile;
    int GT = 0, TP=0, trueTP=0, DET=0;
    int i = 0, j = 0, nameRes, nameTrue, coordX, coordXRes;
    bool finded = false;
    char str[30];
    char strResult[30];
    char filename[4];
    char tmp[4];


    trueFile = fopen(m_trueLocationFileName.toAscii().data(), "r");
    result = fopen(m_userLocationFileName.toAscii().data(), "r");

    for (i=0; i<30; i++)
    {
        str[i]='\0';
    }
    for (i=0; i<30; i++)
    {
        strResult[i]='\0';
    }
    for (j=0; j<4; j++)
    {
        filename[j] = '\0';
        tmp[j] = '\0';
    }

    if (!fgets(strResult, 30, result))
    {
       if (fgets(str, 30, trueFile)) m_recall = 0;
       else m_recall = 1;
       return true;
    }
    DET++;

    i = 0;
    j = 0;

    while ((strResult[i] != ' ') && (strResult [i] != '\t'))
    {

        filename[i] = strResult[i];
        i++;
    }
    i++;
    while ((strResult[i] != ' ') && (strResult[i] != '\t'))
    {
        tmp[j]=strResult[i];
        j++;
        i++;
    }

    i++;

    for (j=0; j<4; j++)
    {
        tmp[j] = '\0';
    }
    j = 0;

    while ((strResult[i] != ' ') && (strResult [i] != '\t'))
    {
        tmp[j] = strResult[i];
        j++;
        i++;
    }

    nameRes = atoi(filename);
    coordXRes = atoi (tmp);

    while (fgets(str, 30, trueFile))
    {
        GT++;
        finded = false;
        for (j=0; j<4; j++)
        {
            filename[j] = '\0';
            tmp[j] = '\0';
        }
        i = 0;
        j = 0;

        while ((str[i] != ' ') && (str [i] != '\t'))
        {

            filename[i] = str[i];
            i++;
        }
        i++;
        while ((str[i] != ' ') && (str [i] != '\t'))
        {
            tmp[j]=str[i];
            j++;
            i++;
        }
        i++;

        for (j=0; j<4; j++)
        {
            tmp[j] = '\0';
        }
        j = 0;

        while ((str[i] != ' ') && (str[i] != '\t'))
        {
            tmp[j] = str[i];
            j++;
            i++;
        }

        nameTrue = atoi(filename);
        coordX = atoi(tmp);
        for (j=0; j<4; j++)
        {
            tmp[j] = '\0';
        }

        while (nameRes < nameTrue)
        {
            if (fgets(strResult, 30, result))
            {
                i = 0;
                j = 0;
                DET++;

                while ((strResult[i] != ' ') && (strResult [i] != '\t'))
                {

                    filename[i] = strResult[i];
                    i++;
                }

                i++;
                while ((strResult[i] != ' ') && (strResult[i] != '\t'))
                {
                    tmp[j]=strResult[i];
                    j++;
                    i++;
                }
                i++;

                for (j=0; j<4; j++)
                {
                    tmp[j] = '\0';
                }
                j = 0;

                while ((strResult[i] != ' ') && (strResult [i] != '\t'))
                {
                    tmp[j] = strResult[i];
                    j++;
                    i++;
                }
                nameRes = atoi(filename);
                coordXRes = atoi (tmp);
                for (j=0; j<4; j++)
                {
                    filename[j] = '\0';
                    tmp[j] = '\0';
                }
            }

        }

        while (nameRes == nameTrue)
        {
            for (j=0; j<4; j++)
            {
                filename[j] = '\0';
                tmp[j] = '\0';
            }
            if (abs(coordX - coordXRes)<=40)
            {
                finded = true;
                TP++;
            }
            if (fgets(strResult, 30, result))
            {
                i = 0;
                j = 0;
                DET++;

                while ((strResult[i] != ' ') && (strResult [i] != '\t'))
                {

                    filename[i] = strResult[i];
                    i++;
                }
                i++;
                while ((strResult[i] != ' ') && (strResult[i] != '\t'))
                {
                    tmp[j]=strResult[i];
                    j++;
                    i++;
                }
                i++;

                for (j=0; j<4; j++)
                {
                    tmp[j] = '\0';
                }
                j = 0;

                while ((strResult[i] != ' ') && (strResult [i] != '\t'))
                {
                    tmp[j] = strResult[i];
                    j++;
                    i++;
                }

                coordXRes = atoi(tmp);
                nameRes = atoi (filename);
            }
            else nameRes = -1;

        }
        if (finded) trueTP++;
    }
    m_precision = double(TP)/DET;
    m_recall = double(trueTP)/GT;
	m_fScore = 2 * m_precision * m_recall / (m_precision + m_recall);

    fclose(result);
    fclose (trueFile);

    return true;
}

QImage Model::scanImage(const QString &imageName)
{
    /* Scan single image for subsequent display.

       You should find all objects on imageName image and mark
       them with rectangles. Return marked image.

       Use Model::detect method to find all objects in image.
    */

    const int n_feat = 2000;

    int i, j;
    int k = 0;

    int x0 = -1;
    double predict_max = 0;

    struct model* modelPedestr;
    QRgb rgb = qRgb ( 0, 255, 0 );

    modelPedestr = load_model(m_modelFileName.toAscii().data());

    QImage image1(imageName);
	QImage image;
    QVector<QVector <int> > patch (250);
    QVector<int> features(n_feat);

    while (k < (image1.width() - 81))
    {
        image = image1.copy( k, 0, 80, 200);
        HOG (image, patch);

        for (i = 0; i<250; i++)
            for (j=0; j<8; j++)
            {
                features [i*8 + j] = patch [i][j];
            }

        struct feature_node* x = Malloc(struct feature_node, n_feat+1);
        x[n_feat].index = -1;
        double prob_estimates[1];
        for ( j = 0; j < n_feat; j++)
        {
            x[j].index = 1+j;
            x[j].value = features[j];
        }

         int predict_label = predict(modelPedestr,x);
         predict_values(modelPedestr,x,prob_estimates);
         if (predict_label == 1)
         {
             if (predict_max < prob_estimates[0])
             {
                 predict_max = prob_estimates[0];
                 x0 = k;
             }
         }
         k = k + 8;
         free(x);
    }

    image = image1.copy( image1.width() - 81, 0, 80, 200);
    HOG (image, patch);

    for (i = 0; i<250; i++)
        for (j=0; j<8; j++)
        {
            features [i*8 + j] = patch [i][j];
        }
    struct feature_node* x = Malloc(struct feature_node, n_feat+1);
    x[n_feat].index = -1;
    double prob_estimates[1];
    for ( j = 0; j < n_feat; j++)
    {
        x[j].index = 1+j;
        x[j].value = features[j];
    }

    int predict_label = predict(modelPedestr,x);
    predict_values(modelPedestr,x,prob_estimates);
    if (predict_label == 1)
    {
        if (predict_max < prob_estimates[0])
        {
            predict_max = prob_estimates[0];
            x0 = image1.width() - 1;
        }
    }
    if (x0 != -1)
    {
        for (j = 0; j < image1.height(); j++)
                {
                    image1.setPixel( x0, j, rgb );
                    image1.setPixel( x0 + 80, j, rgb );
                }
        for (j = x0; j < x0+ 80; j++)
                {
                    image1.setPixel( j, 0, rgb );
                    image1.setPixel( j, (image.height()-1), rgb );
                }
    }
    free(x);
    free_and_destroy_model(&modelPedestr);

    return image1;
}

void Model::HOG (QImage image, QVector<QVector <int> > &patch)
 {
     int i, j, n, m;
     int coordX, coordY;
     QRgb rgb;
     QVector <int> ch(8);
     double gYResult [80][200], gXResult [80][200], Y [80][200];

     double artan[80][200];
     double pi = 3.141592;

     int gY [3][3] = {{-1, -2, -1},
                   {0, 0, 0},
                   {1, 2, 1}};
     int gX [3][3] = {{-1, 0, 1},
                   {-2, 0, 2},
                   {-1, 0, 1}};

     for (i = 0; i < 80; i++)
         for (j = 0; j < 200; j++)
         {
             rgb = image.pixel( i, j );
             Y[i][j] = 0.2125*qRed (rgb) + 0.7154*qGreen (rgb) + 0.0721*qBlue (rgb);
             gYResult[i][j] = 0;
             gXResult[i][j] = 0;
         }
     for (i = 0; i < 80; i++)
         for (j = 0; j < 200; j++)
         {
             for ( n = - 1; n < 2; n++ )
                 for (m = - 1; m < 2; m++)
                 {
                     coordX = i + n;
                     coordY = j + m;
                     if (coordX < 0) coordX = 0;
                     if (coordY < 0) coordY = 0;
                     if (coordX > 79) coordX = 79;
                     if (coordY > 199) coordY = 199;
                     gXResult[i][j] = gXResult[i][j] + Y [coordX][coordY]*gX[1+n][1+m];
                     gYResult[i][j] = gYResult[i][j] + Y [coordX][coordY]*gY[1+n][1+m];
                 }
            if (gXResult[i][j]) artan[i][j] = atan (gYResult[i][j]/gXResult[i][j]);
            else artan[i][j] = pi/2;
         }
     for (i = 0; i < 10; i++)
         for (j = 0; j < 25; j++)
         {
             for (n = 0; n < 8; n++)
                 ch [n] = 0;
             for ( n = i*8; n < 8*(i+1); n++)
                 for (m = j*8; m < 8*(j+1); m++)
                 {

                     if ((artan[n][m] >= -pi/2) && (artan[n][m]) < -3*pi/8 )
                         ch[0]++;
                     else if ((artan[n][m] >= -3*pi/8) && (artan[n][m]) < -pi/4 )
                         ch[1]++;
                     else if ((artan[n][m] >= -pi/4) && (artan[n][m]) < -pi/8 )
                         ch[2]++;
                     else if ((artan[n][m] >= -pi/8) && (artan[n][m]) < 0)
                         ch[3]++;
                     else if ((artan[n][m] >= 0) && (artan[n][m]) < pi/8 )
                         ch[4]++;
                     else if ((artan[n][m] >= pi/8) && (artan[n][m]) < pi/4 )
                         ch[5]++;
                     else if ((artan[n][m] >= pi/4) && (artan[n][m]) < 3*pi/8 )
                         ch[6]++;
                     else if ((artan[n][m] >= 3*pi/8) && (artan[n][m]) <= pi/2 )
                         ch[7]++;

                 }
             patch[ i + j*10] = ch;
         }
 }
