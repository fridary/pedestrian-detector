#ifndef MODEL_H
#define MODEL_H

#include <QFile>
#include <QTextStream>
#include <QImage>

class Model
{
public:
    Model();
    ~Model();

    bool saveModel();
    bool loadModel();
    void sampleAndTrain();
    void classifyDirectory();
    bool estimateQuality();
    QImage scanImage(const QString &imageName);

    void setTrueLocationFileName(const QString &fileName);
    void setUserLocationFileName(const QString &fileName);
    void setModelFileName(const QString &fileName);
    void setDirName(const QString &dirName);

    QString getTrueLocationFileName();
    QString getUserLocationFileName();
    QString getModelFileName();    
    QString getDirName();
    double getPrecision();
    double getRecall();
    double getFScore();

private:
    void sample();
    void trainModel();
    void HOG (QImage, QVector<QVector <int> > &);
    QVector<int> detect(const QImage &image);

    QVector< QVector<int> > m_features;
    QVector<int> m_labels;
    int m_featuresNumber;
    int m_instancesNumber;
    struct model* m_classifier;
    double m_precision;
    double m_recall;
    double m_fScore;
    QString m_trueLocationFileName;
    QString m_userLocationFileName;
    QString m_modelFileName;
    QString m_dirName;
};

#endif // MODEL_H
