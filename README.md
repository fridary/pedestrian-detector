Pedestrian detector
====

![](https://raw.githubusercontent.com/fridary/ultimate-graph/master/detector_1.jpg)

Program detects pedestrians on image. It uses a binary classification. All data input is divided into two classes: the images which have a pedestrians and images in which it is not. The problem is to train a classifier so that a new input image will be able to determine whether it contains a pedestrian.

Here is a simple scheme of the classifier:

- Download the marked images.
- Feature extraction. Each image is described by a set of features called descriptor. Program will use the descriptor based on the histogram of oriented gradients, or HOG.
- Training of the classifier. Classifier is a kind of routine that can, learning on transmitted data, distinguish different classes of images of each other. In this case, the input of the classifier receives its descriptors images.
Testing the classifier on the control sample.


![](https://raw.githubusercontent.com/fridary/ultimate-graph/master/detector_2.jpg)

