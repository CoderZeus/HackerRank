from flask import Flask,request,jsonify

import numpy as np
import cv2
import logging

app = Flask(__name__)

classes = []
with open("coco.names", "r") as f:
    classes = [line.strip() for line in f.readlines()]

@app.route('/')
def hello_world():
    return 'Hello World!'

def get_output_layers(net):

    layer_names = net.getLayerNames()

    output_layers = [layer_names[i[0] - 1] for i in net.getUnconnectedOutLayers()]

    return output_layers

@app.route('/testTwo/',methods=['POST'])
def test_two():
    model = "/home/ubuntu/sharath/yolo/yolov3-tiny.weights"
    config = "/home/ubuntu/sharath/yolo/w.cfg"
    net = cv2.dnn.readNetFromDarknet(config, model)
    img = cv2.imread('/home/ubuntu/sharath/test/000000007454.jpg',1)
    resized = cv2.resize(img, (224, 224))
    blob = cv2.dnn.blobFromImage(resized, 1, (224, 224), (104, 117, 123))
    net.setInput(blob)
    Loutput = get_output_layers(net)
    preds = net.forward(Loutput)
    idx = np.argsort(preds[0])[::-1][0]
    app.logger.warning(net.getLayerNames())
    app.logger.warning(preds)
    app.logger.warning(Loutput) 

    boxes = []
    confidences = []
    classIDs = []

    for output in Loutput:
	# loop over each of the detections
     for detection in output:
		# extract the class ID and confidence (i.e., probability) of
		# the current object detection
      scores = detection[5:]
      classID = np.argmax(scores)
     # confidence = scores[classID]
      app.logger.warning(detection)
    #  text = "Label: {}, {:.2f}%".format(classes[idx],
             
    #  preds[0][idx] * 100)
      app.logger.warning(preds)

      app.logger.warning('#########');
      app.logger.warning(classID)
       #text = blob.shape
    #cv2.putText(img, text, (5, 25),  cv2.FONT_HERSHEY_SIMPLEX,
     #   0.7, (0, 0, 255), 2)
    #cv2.imshow("Image", img)

    return 'test_one with key {} ! '.format(idx)


@app.route('/testOne/',methods=['GET', 'POST'])
def test_one():
    key = request.args.get('key')
    if request.method=='POST':
      key ='POST'
    r = request
    var = jsonify(r.data.decode("utf-8"))
    app.logger.warning(r.headers)
    img = r.files
    app.logger.warning(img)
    # convert string of image data to uint8
    nparr = np.fromstring(r.data, np.uint8)
    # decode image
    #img = cv2.imdecode(nparr, cv2.IMREAD_COLOR)
    model = '/home/ubuntu/sharath/yolo/yolov3-tiny.weights'
    config = '/home/ubuntu/sharath/yolo/yolov3-tiny.cfg'
    net = cv2.dnn.readNetFromDarknet(config, model)
    #net = cv2.dnn.readNetFromDarknet('../yolo/yolov3-tiny.weights','../yolo/cfg')  
    #cv2.dnn.blobFromImages(images, scalefactor=1.0, size, mean, swapRB=True)
    #image = cv2.imread(imagePaths[0])
    # image = r.files.get('image').stream
    ##filestr = request.files['image'].read()
    #convert string data to numpy array
    ##npimg = np.fromstring(filestr, np.uint8)
    # convert numpy array to image
    ##img = cv2.imdecode(npimg, cv2.CV_LOAD_IMAGE_UNCHANGED)

    file = request.files['image']
    npimg = np.fromfile(file, np.uint8)
    file = cv2.imdecode(npimg, cv2.IMREAD_COLOR)

    resized = cv2.resize(file, (224, 224))
    blob = cv2.dnn.blobFromImage(resized, 1, (224, 224), (104, 117, 123))
    net.setInput(blob)
    preds = net.forward()
    cv2.putText(image, text, (5, 25),  cv2.FONT_HERSHEY_SIMPLEX,
	0.7, (0, 0, 255), 2)
    cv2.imshow("Image", image)
    cv2.waitKey(0)
    return 'test_one with key {} ! '.format(key)

