import cv2 as cv
import numpy as np

img = cv.imread('photos/banswara.jpg')
cv.imshow("Image",img)

gray = cv.cvtColor(img,cv.COLOR_BGR2GRAY)
cv.imshow('gray',gray)

blank = np.zeros(img.shape,dtype = 'uint8') #blank image to draw contours onto it



##method 1 to pass edged image using canny and passing canny
# canny = cv.Canny(img,125,175)
# cv.imshow('canny edge',canny)

#no. of contours can be reduced by using blur
# contours , hierarchies = cv.findContours(canny,cv.RETR_LIST,cv.CHAIN_APPROX_SIMPLE)
# print(f'{len(contours)}contour found')

##method 2 usinfthreshhold
#thresh_binanry means white or black
ret , thresh = cv.threshold(gray,125,255,cv.THRESH_BINARY)
contours , hierarchies = cv.findContours(thresh,cv.RETR_LIST,cv.CHAIN_APPROX_SIMPLE)
print(f'{len(contours)}contour found')
cv.imshow('THRESH',thresh)

cv.drawContours(blank,contours , -1,(0,0,255),1)
cv.imshow('contours drawn',blank)

cv.waitKey(2000)