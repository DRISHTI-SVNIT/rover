import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt

img = cv.imread('photos/banswara.jpg')
cv.imshow("Image",img)

gray = cv.cvtColor(img,cv.COLOR_BGR2GRAY)
cv.imshow('gray',gray)

#BGR to HSV and converse
hsv = cv.cvtColor(img,cv.COLOR_BGR2HSV)
cv.imshow('hsv',hsv)

#BGR to LAB and converse
lab = cv.cvtColor(img,cv.COLOR_BGR2LAB)
cv.imshow('lab',lab)

#bgr to rgb and converse
rgb = cv.cvtColor(img,cv.COLOR_BGR2RGB)
cv.imshow('rgb',rgb)

#matplotlib plot in rgb format but cv.imread read image in bgr format
plt.imshow(img)
plt.show()

plt.imshow(rgb)
plt.show()


cv.waitKey(5000)