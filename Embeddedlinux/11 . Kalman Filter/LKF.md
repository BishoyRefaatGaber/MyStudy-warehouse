#### Kalman Filter in one dimension

- The Kalman Filter is based on five equations : 
	- The state update equation
	- Covariance update equation
	- Kalman Gain equation
	- State Extrapolation equation
	- Covariance Extrapolation equation
- ![[Screenshot from 2024-03-15 09-05-35.png]]



- ***measurement uncertainty*** : the standard deviation (σ) of the measurement errors.also called ***measurement error***
- We denote the ***state estimate variance*** by $\rho$.
- We denote the ***measurement variance*** by $r$.
---
##### Kalman filter components
- The estimate uncertainty extrapolation for a constant dynamics
	$p̂_{n+1,n }= p̂_{n,n}$
- The estimate uncertainty extrapolation for a constant velocity dynamics
	$p^x_{n+1,n} = p^x_{n,n} + ∆t^2 · p^v_{n,n}$
	$p^v_{n+1,n} = p^v_{n,n}$
Where:
	$p^x$  is the position estimate variance.
	$p^v$  is the velocity estimate variance.
- State Update Equation
	$x̂_{n,n} = x̂_{n,n−1} +\frac { p_{n,n−1}}{{p_{n,n−1} + r_n}} (z_n − x̂_{n,n−1} )$
- State Update Equation
	$K_n =\frac {p_{n,n−1}}{ p_{n,n−1} + r_n}$
Where:
	$p_{n,n−1}$ is the extrapolated estimate variance
	$r_n$ is the measurement variance
	$0 ≤ Kn ≤ 1$
- Covariance Update Equation
	$p_{n,n} = (1 − K_n ) p_{n,n−1}$

---
##### Putting all together

- The filter inputs are:
	- Initialisation
		The initialisation is performed only once, and it provides two parameters:
		- Initial System State ($x̂_{0,0}$ )
		- Initial State Variance ($p_{0,0}$ )
			The initialisation parameters can be provided by another system, another process (for instance, a search process in radar), or an educated guess based on experience or theoretical knowledge. Even if the initialization parameters are not precise, the Kalman filter can converge close to the true value.
	- Measurement
		- The measurement is performed for every filter cycle, and it provides two
		- parameters:
			- Measured System State ($z_n$ )
			- Measurement Variance ($r_n$ )
- The filter outputs are:
	- System State Estimate ($x̂_{n,n}$ )
	- Estimate Variance ($p_{n,n}$ )


![[Screenshot from 2024-03-15 10-04-43.png]]



#### The Kalman Filter’s block diagram
![[Screenshot from 2024-03-15 10-10-47.png]]


- Step 0: Initialisation
	- The initialisation is performed only once, and it provides two parameters:
		- Initial System State ($x̂_{0,0}$)
		- Initial State Variance ($p_{0,0}$)
	- The initialisation is followed by prediction.
- Step 1: Measurement
	- The measurement process provides two parameters:
		- Measured System State ($z_n$)
		- Measurement Variance ($r_n$)
- Step 2: State Update
	- The state update process is responsible for the state estimation of the current state of the system.
	- The state update process inputs are:
		- Measured Value ($z_n$)
		- A Measurement Variance ($r_n$)
		- A prior Predicted System State Estimate ($x̂_{n,n−1}$)
		- A prior Predicted System State Estimate Variance ($p_{n,n−1}$)
	- Based on the inputs, the state update process calculates the Kalman Gain and provides two outputs:
		- Current System State Estimate ($x̂_{n,n}$)
		- Current State Estimate Variance ($p_{n,n}$)
- These parameters are the Kalman Filter outputs.
- Step 3: Prediction
	- The prediction process extrapolates the current system state estimate and its variance to the next system state based on the dynamic model of the system.
	- At the first filter iteration, the initialisation is treated as the Prior State
Estimate and Variance. The prediction outputs are used as the Prior (predicted) State Estimate and Variance on the following filter iterations.


##### Adding process noise

- The ***Process Noise Variance*** is denoted by the letter $q$.
- The Covariance Extrapolation Equation shall include the Process Noise
Variance.
- The Covariance Extrapolation Equation for constant dynamics is:
	$p_{n+1,n} = p_{n,n} + q_n$

![[Screenshot from 2024-03-15 10-33-47.png]]



#### Multivariate Kalman Filter


- Expectation of the random variable $E(X) = µ_X$
- ![[Screenshot from 2024-03-15 10-37-46.png]]
- ![[Screenshot from 2024-03-15 10-38-23.png]]
-  ![[Screenshot from 2024-03-15 10-39-07.png]]

- The Kalman Filter output is a ***multivariate random variable***. A ***covariance matrix*** describes the squared uncertainty of the multivariate random variable.

- ![[Screenshot from 2024-03-15 10-42-16.png]]

- The correlation is positive; therefore, the covariance is positive.
- The correlation is negative; therefore, the covariance is negative.

- The covariance between population X and population Y with size N is given by:
- $$COV (X, Y ) =
\frac{1}{N}\sum_{i=1}^{N} 
(x_i − µ_x )(y_i − µ_y )
= \frac{1}{N}\sum ^N_{i=1}
(x_i y_i ) − µ_x µ_y
$$
- The covariance of a sample with size N is normalised by N − 1:
$$COV (X, Y ) =
\frac{1}{N-1}
\sum^{N} _{i=1}(x_i − µ_x )(y_i − µ_y )
= \frac{1}{N-1}
\sum^{N} _{i=1}(x_i y_i )- \frac{N}{N-1}( µ_xµ_y )
$$
#### Linear Kalman Filter Equations

- ***State Extrapolation Equation*** 
	- $$x̂_{n+1,n} = F x̂_{n,n} + Gu_n + w_n$$
	Where:
		$x̂_{n+1,n}$       is a predicted system state vector at time step $n + 1$
        $x̂_{n,n}$          is an estimated system state vector at time step $n$
        $u_n$            is a control variable or input variable - a measurable                           (deterministic) input to the system
		$w_n$           is a process noise or disturbance - an unmeasurable input                 that affects the state
		$F$            is a state transition matrix
		$G$            is a control matrix or input transition matrix (mapping                          control to state variables)
--> In the literature, state extrapolation equation is also called:
-  Predictor Equation
- Transition Equation
- Prediction Equation
- Dynamic Model
- State Space Model
- ![[Screenshot from 2024-03-15 11-36-52.png]]

- ***Covariance Extrapolation Equation***
	$$P_{n+1,n} = F P_{n,n} F^T + Q$$
	Where:
	$P_{n,n}$      is the squared uncertainty of an estimate (covariance matrix) of                the current state
	$P_{n+1,n}$   is the squared uncertainty of a prediction (covariance matrix) for               the next state
	$F$          is the state transition matrix that we derived in Appendix C                        (“Modeling linear dynamic systems”)
	$Q$          is the process noise matrix


- Constructing the process noise matrix Q
- $$Q = \begin{bmatrix}
q_{11}&0&\cdots&0 \\
0&q_{11}&\cdots&0 \\
\vdots&\vdots&\ddots&\vdots\\
0&0&\cdots &q_{11} \\
\end{bmatrix}$$
--> There are two models for the environmental process noise.
-  Discrete noise model
	- The discrete noise model assumes that the noise is different at each period but is constant between periods.
	- $$Q=\begin{bmatrix}
	V(x)&COV(x,v)\\
	COV(v,x)&V(v) 
	\end{bmatrix}$$
	- Projection using the state transition matrix
		- If the dynamic model doesn’t include a control input, we can project the random variance in acceleration $σ_a^2$ on our dynamic model using the state transition matrix.
		- Let us define a matrix $Q_a$ :
			- $$Q_a=\begin{bmatrix}
			0&0&0\\
			0&0&0\\
			0&0&1
			\end{bmatrix}\sigma_a^2$$
		- The process noise matrix is:
			- $Q = F Q_a F^T$	
	- Projection using the control matrix
		- $Q=G\sigma_a^2G^T$
-  Continuous noise model
	- The continuous model assumes that the noise changes continuously over time.
	- $$Q_c=\int_0^{\Delta t}Qdt$$
- ***Measurement Equation***
	- $$z_n=Hx_n+v_n$$
	- Where:
		$z_n$       is a measurement vector
		$x_n$      is a true system state (hidden state)
		$v_n$      is a random noise vector
		$H$      is an **observation matrix**
	- **The observation matrix**
		- Scaling
		- State selection
			- Sometimes certain states are measured while others are not.
		- Combination of states
			- Sometimes some combination of states can be measured instead of each separate state.
![[Screenshot from 2024-03-15 12-09-23.png]]


- ***State Update Equation***
	- $$\hat{x}_{n,n} = \hat{x}_{n,n-1}+K_n(z_n-H\hat{x}_{n,n-1})$$
	- Where:
		$x̂_{n,n}$         is an estimated system state vector at time step $n$
		$x̂_{n,n−1}$      is a predicted system state vector at time step $n − 1$
		$K_n$          is a Kalman Gain
		$z_n$           is a measurement
		$H$            is an observation matrix
![[Screenshot from 2024-03-15 12-14-41.png]]



- ***Covariance Update Equation***
$$P_{n,n} = (I − K_n H) P_{n,n−1} (I − K_n H)^T + K_n R_n K_n^T$$
	Where:
		$P_{n,n}$         is the covariance matrix of the current state estimation
		$P_{n,n−1}$      is the prior estimate covariance matrix of the current state                (predicted at the previous state)
		$K_n$           is a Kalman Gain
		$H$             is the observation matrix
		$R_n$            is the measurement noise covariance matrix
		$I$               is an Identity Matrix (the n × n square matrix with ones on                  the main diagonal and zeros elsewhere)

- ***The Kalman Gain***
- $$K_n = P_{n,n−1} H^T (HP_{n,n−1} H ^T + R_n)^{-1}$$
	Where:
		$K_n$         is the Kalman Gain
		$P_{n,n−1}$    is the prior estimate covariance matrix of the current state
              (predicted at the previous step)
		$H$          is the observation matrix
		$R_n$         is the measurement noise covariance matrix



![[Screenshot from 2024-03-15 12-25-47.png]]


![[Screenshot from 2024-03-15 12-26-34.png]]

![[Screenshot from 2024-03-15 12-27-10.png]]


