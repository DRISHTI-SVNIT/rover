import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt

img = cv.imread('photos/banswara.jpg')
cv.imshow("Image",img)

# gray = cv.cvtColor(img,cv.COLOR_BGR2GRAY)
# cv.imshow("gray",gray)

# #grayscale histogram
# #it takes input as a list but since we have only one image --> [gray] ; next is index of image compute a histograme for since we have only one image[0] , next is mask if we want to compute histograme for specific part of image
# gray_hist = cv.calcHist([gray],[0],None, [256] ,[0,256] )

# plt.figure()
# plt.title('grayscale Histogram')
# plt.xlabel('bins')
# plt.ylabel('# of pixel')
# plt.plot(gray_hist)
# plt.xlim([0,256])
# plt.show()


#color histogram

colors = ('b','g','r')
for i,col in enumerate(colors):
    hist = cv.calcHist([img],[i],None,[256],[0,256])
    plt.plot(hist,color=col)
    plt.xlim([0,256])
plt.show()

cv.waitKey(3000)
