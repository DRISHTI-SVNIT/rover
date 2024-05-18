import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt

img = cv.imread('photos/banswara.jpg')
cv.imshow("Image",img)
gray = cv.cvtColor(img,cv.COLOR_BGR2GRAY)
cv.imshow("gray",gray)

#laplacian
lap = cv.Laplacian(gray,cv.CV_64F)
lap = np.uint8(np.absolute(lap))
cv.imshow("Laplacian",lap)

#sobel
sobelx = cv.Sobel(gray,cv.CV_64F,1,0)
sobely = cv.Sobel(gray,cv.CV_64F,0,1)
combined_soble = cv.bitwise_or(sobelx,sobely)

cv.imshow("sobelx",sobelx)
cv.imshow("sobely",sobely)
cv.imshow("combined_sobel",combined_soble)

cv.waitKey(20000)