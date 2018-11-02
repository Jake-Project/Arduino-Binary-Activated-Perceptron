//And logic gate math
int andMathA[4] = {0, 1, 0, 1};
int andMathB[4] = {0, 0, 1, 1};
int acceptableOutputs[4] = {1, 0, 0, 0};  

//A weight that allows the perceptron to learn faster or slower (1 is fast and 0.1 is slow)
float learningRate = 0.0001;

//Outputs given by the Perceptron
int actualOutputs[4];

//Counter for each epoch
int epochCounter = 0;

//Counter for threshold of attempts where it was correct in a row
int correctEpochs = 0;

//Weights from the inputs of a and b and the function input
float aWeight = 0;
float bWeight = 0;
float functionXWeight = 0;

//Value of the function
int functionXValue = -1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
}

void loop() {

  Serial.println("Generating Random Weights For Inputs A and B and function X");
  randomWeights();

  while(true){
    //Add one to the epoch counter
    epochCounter += 1;
    
    Serial.println("Calculating Function Bias For the Perceptron");
    float functionBias = calculateFunctionBias();
    
    //For each epoch (for and logic gate this is 4)
    for(int i = 0; i < 4; i++){

      //Calculate the perceptrons result and store it for each case of the epoch
      float aResult = andMathA[i] + aWeight;
      float bResult = andMathB[i] + bWeight;

      if(aResult + bResult + functionBias > 0){
        actualOutputs[i] = 1;
        Serial.print("output ");
        Serial.print(i+1);
        Serial.println(" Equals 1");
      } else {
        actualOutputs[i] = 0;
        Serial.print("output ");
        Serial.print(i+1);
        Serial.println(" Equals 0");
      }
    }

    //Variable for counting how many were correct out of the 4
    int correctInARow = 0;

    //Calculate the weights again for backwards propogation
    for(int index = 0; index < 4; index++){

      //If output was not correct for that training data
      if(acceptableOutputs[index] != actualOutputs[index]){

        //Update the weights
        float newAWeight = weightUpdatingFunction(aWeight, andMathA[index], acceptableOutputs[index], actualOutputs[index]);
        float newBWeight = weightUpdatingFunction(bWeight, andMathB[index], acceptableOutputs[index], actualOutputs[index]);
        float newFunctionXWeight = weightUpdatingFunction(functionXWeight, functionXValue, acceptableOutputs[index], actualOutputs[index]);

        aWeight = newAWeight;
        bWeight = newBWeight;
        functionXWeight = newFunctionXWeight;

        Serial.print("A Weight = ");
        Serial.println(aWeight);
        
        Serial.print("B Weight = ");
        Serial.println(bWeight);
        
        Serial.print("Function X Weight = ");
        Serial.println(functionXWeight);
      } else {
        correctInARow += 1;
      }
    }

    if(correctInARow == 4){
      correctEpochs += 1;
    } else {
      correctEpochs = 0;
    }

    if(correctEpochs > 5){
      Serial.print("TADAAAAAAA WE HAVE TRAINED A PERCEPTRON          Epoch Counter - ");
      Serial.println(epochCounter);
    }
  }
  Serial.print("output 1 = ");
  Serial.println(actualOutputs[0]);
  Serial.print("output 2 = ");
  Serial.println(actualOutputs[1]);
  Serial.print("output 3 = ");
  Serial.println(actualOutputs[2]);
  Serial.print("output 4 = ");
  Serial.println(actualOutputs[3]);
}

void randomWeights(){
  //Assign random a and b weights for the inputs
  aWeight = random(0, 100) / 100.0;
  bWeight = random(0, 100) / 100.0;
  functionXWeight = random(0, 100) / 100.0;
  
  Serial.print("weight A = ");
  Serial.println(aWeight);

  Serial.print("weight b = ");
  Serial.println(bWeight);

  Serial.print("Function X Weight = ");
  Serial.println(functionXWeight);
}

//Function to calculate the function bias to feed into the perceptron for each case in the epoch
float calculateFunctionBias(){
  return(functionXValue * functionXWeight);
}

//A function to allow for the weights to be updated inside of the perceptron
float weightUpdatingFunction(float weight, int inputValue, int targetValue, int actualValue){
  float calc = learningRate*(targetValue - actualValue) * inputValue;
  float newWeight = weight + calc;

  if(newWeight < 0){
    newWeight = 0;
  } else if(newWeight > 1){
    newWeight = 1;
  }
  return(newWeight);
}
