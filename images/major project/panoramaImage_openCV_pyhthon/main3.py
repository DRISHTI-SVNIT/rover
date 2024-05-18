from __future__ import print_function
import cv2
import os
import numpy as np

mainfolder = 'Images'
myFolders = os.listdir(mainfolder)
print(myFolders)

for folder in myFolders:
    path = mainfolder +'/'+folder
    print(path)
    images=[]
    myList = os.listdir(path)
    print(f"total no of image detected {len(myList)}")
    for imgN in myList:
        dim=(1024,768)
        imagepath = path+'/'+imgN
        print(imagepath)
        image = cv2.imread(imagepath,cv2.IMREAD_COLOR)
        image = cv2.resize(image,dim,interpolation=cv2.INTER_AREA)
        images.append(image)


    stitcher = cv2.Stitcher.create()
    ret,pano = stitcher.stitch(images)
    print(pano.shape[0])
    print(pano.shape[1])
    #height = img.shape[0]
    #width = img.shape[1]
    pano = pano[100:pano.shape[0]-100,300:pano.shape[1]-300]
    

    for alpha in np.arange(0.5,1,0.1)[::-1]:
        overlay = pano.copy()
        output1 = pano.copy()

        cv2.rectangle(overlay,(433,464),(937,526),(191,165,143),-1)
        #cv2.putText(overlay,"hello".format(alpha),(10,30),cv2.FONT_HERSHEY_SIMPLEX,1.0,(58,79,122),3)

        cv2.addWeighted(overlay,alpha,output1,1-alpha,0,output1)
        #print("alpha={},beta={}".format(alpha,1-alpha))

    for alpha in np.arange(0.8,1,0.1)[::-1]:
        overlay = output1.copy()
        outputFinal = output1.copy()

        cv2.putText(overlay,"Hello".format(alpha),(10,30),cv2.FONT_HERSHEY_SIMPLEX,1.0,(71,38,10),3)

        cv2.addWeighted(overlay,alpha,outputFinal,1-alpha,0,outputFinal)
        #print("alpha={},beta={}".format(alpha,1-alpha))


        if ret==cv2.STITCHER_OK:
            print("panorama generated")
            cv2.imshow(folder,outputFinal)
            cv2.waitKey(10)
        else:
            print("Error during Stitching")

cv2.waitKey(0)