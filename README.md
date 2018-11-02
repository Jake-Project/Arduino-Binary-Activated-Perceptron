# Explanation For Development

For my Machine Learning module in my third year at Aberystwyth University we were shown slides which talked about Perceptrons and their use in a Neural Network.
I decided to create a Perceptron which uses a Binary Activation Function in order to test a truth table and to get the correct output for AND.

A - {0|1|0|1}
B - {0|0|1|1}

Expected Output - {0|0|0|1}


## What I Learned

I learned how a Perceptron adjusts the weights from a, b and the Bias Function (X) through backwards propogation to figure out the solution to the problem.
I also noted that the learning rate greatly effects the Perceptron and if this is too high can lead to a recurring pattern of weights which gets suck in a sequence that it cannot escape which stops the Perceptron from being trained.
Unfortunately a single Perceptron which uses the Binary Activation Function cannot work out XOR.

## Future Ideas

I wish to create a simple Neural Network compromising of a few layers in either Javascript using the Express framework or by using Java in the future.
