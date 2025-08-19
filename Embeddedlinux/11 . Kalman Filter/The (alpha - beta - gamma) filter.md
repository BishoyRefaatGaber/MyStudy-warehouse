
- At the time n, the estimate $x̂_{n,n}$ would be the average of all previous measurements:
	- $$\hat{x}_{n,n} = \frac{1}{n}(z_1+z_2+\cdots +z_{n-1}+z_n) = \frac{1}{n}\sum_{i=1}^{n}(z_i)$$
- Example Notation:
--> $x$             is the true value of the weight
--> $z_n$            is the measured value of the weight at time n
--> $\hat{x}_{n,n}$         is the estimate of x at time n (the estimate is made after taking the measurement $z_n$)
--> $\hat{x}_{n+1,n}$      is the estimate of the future state $(n + 1)$ of $x$. The estimate is made at the time n. In other words, $x̂_{n+1,n}$ is a predicted state or extrapolated state
--> $\hat{x}_{n-1,n-1}$   is the estimate of $x$ at time $n − 1$ (the estimate is made after taking the measurement $z_{n−1}$ )
--> $\hat{x}_{n,n-1}$      is a prior prediction - the estimate of the state at time $n$. The prediction is made at the time $n − 1$

###### State Update Equation
$$\hat{x}_{n,n} = \hat{x}_{n,n-1}+\frac{1}{n}(z_n-\hat{x}_{n,n-1})\equiv\hat{x}_{n,n} = \hat{x}_{n,n-1}+\alpha_n(z_n-\hat{x}_{n,n-1})$$
![[Screenshot from 2024-03-15 00-09-28.png]]

- The Kalman Filter requires the initial guess as a preset, which can be very rough.

- ![[Screenshot from 2024-03-15 00-18-34.png]]

###### State Extrapolation Equation  
- system of equations extrapolates the current state to the next state (prediction).also called a ***Transition Equation*** or a ***Prediction Equation***
- ***In the example book (moving aircraft with const velocity)*** 
	- The state update equation for position and velocity 
	- $$\hat{x}_{n,n} = \hat{x}_{n,n-1}+\alpha(z_n-\hat{x}_{n,n-1})$$
	- $$\hat{\dot{x}}_{n,n} = \hat{\dot{x}}_{n,n-1}+\beta(\frac{z_n-\hat{x}_{n,n-1}}{\Delta t}) $$
- ***lag error*** : A constant gap between true or measured values and estimates. Other common names for the lag error are:
• Dynamic error
• Systematic error
• Bias error
• Truncation error

-------

The α − β − γ filter (sometimes called g-h-k filter) considers a target acceleration.
Thus, the State Extrapolation Equations become:

- The State Extrapolation Equations for position, velocity, and acceleration
$x̂_{n+1,n} = x̂{n,n} + \hat{ẋ}_{n,n} ∆t + \hat{ẍ}_{n,n} \frac{∆t^2}{2}$
$\hat {ẋ}_{n+1,n} = \hat{ẋ}_{n,n} + \hat{ẍ}_{n,n} ∆t$
$\hat{ẍ}_{n+1,n} = \hat{ẍ}_{n,n}$
Where $ẍn$ is acceleration (the second derivative of $x$ ).

The State Update Equations for position, velocity, and acceleration
$x̂_{n,n} = x̂_{n,n−1} + α (z_n − x̂_{n,n−1} )$
$\hat{ẋ}_{n,n} = \hat{ẋ}_{n,n−1} + β  (\frac{z_n − x̂_{n,n−1}}{∆t})$
$\hat{ẍ}_{n,n} = \hat{ẍ}_{n,n−1} + γ(\frac{z_n − x̂_{n,n−1}}{0.5∆t^2})$

-----
Summary of the α − β − (γ) filter : 
- There are many types of α − β − (γ) filters, and they are based on the same principle:
- The current state estimation is based on the state update equations.
-  The following state estimation (prediction) is based on the dynamic model equations.
- The main difference between these filters is the selection of weighting coefficients α − β − (γ). 
- Some filter types use constant weighting coefficients; others compute weighting coefficients for every filter iteration (cycle).
- The choice of the α, β and γ is crucial for proper functionality of the estimation algorithm.
- The following list includes the most popular α − β − (γ) filters:
	- Wiener Filter
	- Bayes Filter
	- Fading-memory polynomial Filter
	- Expanding-memory (or growing-memory) polynomial Filter
	- Least-squares Filter
	- Benedict–Bordner Filter
	- Discounted least-squares α − β Filter
	- Critically damped α − β Filter
	- Growing-memory Filter
	- Kalman Filter
	- Extended Complex Kalman Filter
	- Gauss-Hermite Kalman Filter
	- Cubature Kalman Filter
	- Particle Filter

---


