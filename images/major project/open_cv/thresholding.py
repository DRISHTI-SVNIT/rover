import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt

img = cv.imread('photos/banswara.jpg')
cv.imshow("Image",img)

gray = cv.cvtColor(img,cv.COLOR_BGR2GRAY)
cv.imshow('gray',gray)

#simplethresholding
#(value<150-->0,value>150-->250)
threshold , thresh = cv.threshold(gray,150,255,cv.THRESH_BINARY)
cv.imshow('thresh',thresh)

#(value<150 --> 250,value>150 --> 0)
threshold , thresh_inv = cv.threshold(gray,150,255,cv.THRESH_BINARY_INV)
cv.imshow('thresh_inv',thresh_inv)


#adaptive thresholding
adaptive_thresh = cv.adaptiveThreshold(gray,255,cv.ADAPTIVE_THRESH_GAUSSIAN_C,cv.THRESH_BINARY,11,3)
cv.imshow('adaptive_thresh',adaptive_thresh)


cv.waitKey(5000)