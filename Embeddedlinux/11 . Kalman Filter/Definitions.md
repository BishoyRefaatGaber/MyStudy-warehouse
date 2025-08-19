- ***System State*** :  the set of target parameters \[x, y, z, vx , vy , vz , ax , ay , az \] 
--> The current state serves as the input for the prediction algorithm, while the algorithm’s output is the future state

- ***Dynamic Model or State Space Model*** : the equations of system  
- ***Measurement Noise*** : radar calibration,beam width, and signal-to-noise ratio of the returned echo. The random errors or uncertainties in the radar measurement  
- ***Process Noise*** : misalignment between the motion equations and the actual target motion results in an error or uncertainty in the dynamic model
- ***Kalman Filter*** : The most common tracking and prediction algorithm 
- ***Mean*** and ***Expected Value*** are closely related terms.
- ***Mean*** = ***Expected Value*** if the system states are hidden and we don't use the entire population 
- ***The Variance $\sigma ^ 2$***  : is a measure of the spreading of the data set from its mean.
- ***The Standard Deviation $\sigma$*** : is the square root of the variance.
	- $$\sigma ^2 = \frac{1}{N-1}\sum_{n=1}^N(x_n - \mu)^2$$
- ***Random variable*** describes the hidden state of the system.
- ***moments*** the probability density function is characterised. 
	- The moments of the random value are expected values of powers of the random variable.
	- skew, mean, variance,$\cdots$ 
- ***Estimate*** Is evaluating the hidden state of the system.
-  ***Estimate error*** : the difference between the estimates and the true values.
- ***Accuracy*** Indicates how close the measurement is to the true value.
- ***Precision*** describes the variability in a series of measurements of the same parameter.
	- Accuracy and precision form the basis of the estimate.
- ***biased systems*** Low-accuracy systems since their measurements have a built-in systematic error (bias).
- ***Accuracy of the measurements*** The offset between the mean of the measurements and the true value, also known as ***bias*** or ***systematic measurement error***.
- ***Measurement precision*** the dispersion of the distribution, also known as the ***measurement noise***, ***random measurement error***, or ***measurement uncer-tainty***.
-  ***Process Noise*** : the uncertainty of the dynamic model.
- ***Covariance*** is a measure of the strength of the correlation between two or more sets of random variates.
- ***covariance matrix*** : is a square matrix that represents the covariance between each pair of elements in a given multivariate random variable.
- For a n - dimensional random variable, the covariance matrix is:
- $$\sum = \begin{bmatrix}
\sigma^2_1 & \sigma_{12} & \cdots&\sigma_{1n}\\
\sigma_{21} & \sigma^2_{2} & \cdots & \sigma_{2n}\\
\vdots &\vdots &\ddots &\vdots \\
\sigma_{n1} & \sigma_{n2} & \cdots&\sigma^2_{n}\\
\end{bmatrix}$$
- The covariance matrix of the vector $x$
	$COV (x) = E ((x − µ_x ) (x − µ_x )^\intercal)$
	Where $µ_X$is the mean of the random variable.

