
#### Basic Probability

- Probability is a mathematical way of described the likelihood of an event happening . For any Event A the probability is :
$$ 0 \leq P(A) \leq 1$$ 
- If S is a set of possible events then the sum of all probabilities is the set must be equal to : 

$$ \sum_{e\in S}P(e) = 1 $$
- If we know the probability of event A occurring then the probability of the event A not occurring is simply :

$$P(\bar{A}) = 1 - P(A)$$
- Mutually Exclusive Events 
$$P(A\ and\ B) = 0 $$
$$P(A\ or\ B ) = P(A) + P(B) = 1 $$

- Not Mutually Exclusive
$$P(A\ and\ B) \neq 0 $$
$$P(A\ or\ B) = P(A) + P(B) - P(A and B)$$

- Conditional Probability
	- Events can be considered ***Independent*** if the likelihood of one event does not affect the likelihood of another occurring 
	- ***Dependent*** events are the opposite when one event occurs it changes the probability of the other events
	- The Probability of Event A and Event B occurring if they are dependent :
	$$P(A\ and\ B) = P(A)P(B|A)$$
	- **** *Conditional probability***
	$$P(A|B) = \frac {P(A\ and\ B)}{P(B)}$$
		- P(A|B) -> Conditional probability
		- P(A and B) -> joint probability
		- P(B) -> Marginal probability
	
	- ***Independent Events***
$$P(A\ and\ B) = P(A)P(B)$$
$$P(A|B) = P(A)$$
$$P(B|A) = P(B)$$
- Bayes' Theorem
	- $$P(A|B) = \frac{P(B|A)P(A)}{P(B)}$$
	-  P(A|B) -> Conditional probability (Likelihood Event A given Event B occurs)
		- ***[Posterior Probability ]***
	- P(B|A) ->  Conditional probability (Likelihood Event B given Event A occurs)
		- ***[Likelihood]***
	- P(A) -> Marginal Probability (Likelihood Event A occurring)
		- ***[Priori Probability]***
	- P(B) -> Marginal Probability (Likelihood Event B occurring)
		- ***[Evidence]***

#### Probability Density Function

- Random Variable
	- Mathematics is a very precise and deterministic field , so a way of expressing random events and uncertainties is required 
	- A random variable is a way to mathematically express stochastic outcomes as real numbers
	$$X : S \rightarrow E$$
		- The random variable X has the possibility of being any of the real numbers in E
		- However once the experiment has been carried out the value of the random variable or outcome has been determined You can then treat the random value as any normal algebraic value
		- Let's say we have a random variable  X but we would like to know how likely each outcome is to  occur. Is each outcome equally as likely or are some outcomes more likely to occur than others???
		- We describe and quantify this with ***Probability Density Function*** 
		- PDFs measure the relative likelihood or probabilitiy that a specific outcome will occur.
![[Pasted image 20240310150352.png]]

$$P(a \le X \le b) = \int_{a}^{b} f_x(x)dx$$
$$\int_{-\infty}^{\infty}f_x(x)dx = 1 $$


- Expectation Operator
	- Now that we have defined what a PDF for a random variable is, and how to calculate the probability of certain events happening. A core operation that can be applied to a PDF is the expectation operator:
	- $$E(X) = \int_{-\infty}^{\infty}xf_x(x)dx$$
	- The expectation value or mean of the random variable is usually for simplicity written as : 
	- $$\bar{X} = \bar{x} = E(X)$$
- Distribution Statistics Properties 
	- It is very useful to be able to describe a probability density function or distribution in a few key properties :
		- Mean 
		- Variance 
		- Skew
	- We can now calculate these properties of a distribution by using the expectation operator 
	- The mean of a distribution is just the expectation value:
		- $$\bar{x} = E(X)$$
	- The variance of a distribution is a measurement of how much the distribution varies from the mean:
	- $$\sigma^2_X = E\ [\ (X - \bar{x})^2\ ] $$           $\sigma^2_X = E\ [\ (X^2 - X\bar{x}\ +\bar{x}^2)\ ]$
	    $= E\ [\ X^2\ -\ X\bar{x}\ +\ \bar{x}^2\ ]$
	   $\ =\ E(X^2)\ -\ 2\bar{x}^2\ +\ \bar{x}^2$
	   $\ =\  E(X^2)\ -\ \bar{x}^2$ 
	- $$X \sim (\bar{x} , \sigma^2_X)$$
	- The skew of a distribution a measure the asymmetry of the distribution from the mean :  
	- $$skew\ =\ E[(X\ -\ \bar{x})^3]$$
	- $$skewness\ =\ skew/\sigma^3_X$$
	-  ![[Pasted image 20240310150658.png]]
#### Multivariate Probability 

-  Let X be a random variable with a pdf of $f_X(x)$ and also let Y be a random variable with a pdf of $f_Y(y)$. It is possible to define the pdf for the joint probability as $f_{XY}(x,y)$ or $f(x,y)$ for short
- Joint Probability : 
$$P(a\ \le\ X\ \le\ b\ and\ c\ \le\ Y\ \le\ d)\ =\ \int_c^d\int_a^bf(x,y)dxdy$$
- Marginal Density Function : 
$$f_X(x)\ =\ \int_{-\infty}^{\infty}f(x,y)dy$$
$$f_Y(y)\ =\ \int_{-\infty}^{\infty}f(x,y)dx$$

- Expected Value
	- Single Random Variable : 
	$$E \ [ \ g(x)\ ]\ =\ \int_{-\infty}^\infty g(x)f_X(x)dx$$
	- Multiple Random Variable : 
	$$E \ [ \ g(x)\ ]\ =\ \int_{-\infty}^\infty\int_{-\infty}^\infty g(x,y)f_X(x,y)dxdy$$
- Independent Random Variables
	- Basic Probability Condition : 
		- $$P(A\ and\ B)\ =\ P(A)P(B)$$
	- Density Function Condition : 
		- $$f_{XY}(x,y)\ =\ f_X(x)f_Y(y)$$
	- Expected Value of Multiplication of Independent Random Variables
		- $$E(XY)\ =\ \int\int XYf(x,y)dxdy$$
		- $$E(XY)\ =\ \int\int XYf_X(x)f_Y(y)dxdy$$
		- $$E(XY)\ =\ \int XYf_X(x)dx\int f_Y(y)dy$$
		- $$E(XY)\ =E(X)E(Y)$$
	- Expected Value of Sum of Independent Random Variables
		- $$z(x,y)\ =\ g(x)\ +\ h(y)$$
		- $$E\ [\ z(x,y)\ ]=E\ [\ \ g(x)\ +\ h(y)\ ]$$
		- $$E(z)\ =\ \int\int [g(x)\ +\ h(y)]f(x,y)dxdy$$
		- $$E(z)\ =\ \int\int g(x)f_X(x)f_Y(y)dxdy \ + \int\int \ h(y)f_X(x)F_Y(y)dxdy$$
		- $$E(z)\ =\ \int g(x)f_X(x)dx \int f_Y(y)dy \ + \int\ h(y)f_Y(y)dy\int f_X(x)dx$$
		- $$E(z)\ =\ E[g(x)]\ +\ E[h(y)]\longrightarrow z=x+y\ \rightarrow E(x+y)=E(x)+E(y)$$
- Dependant Random Variables
	- The random variables might not be independent, there might be some correlation between the two
		- Covariance:
			- $$C_{XY}\ =\ E[(X-\bar{x})(Y-\bar{y})]\ =\ E(XY)-\bar{x}\bar{y}$$
		- Correlation Coefficient : 
			- $$\rho \ =\ \frac{C_{XY}}{\sigma_x\sigma_y}$$
	- We can generate single random variables into vector form:
		- $$\begin{equation*}
X = 
\begin{bmatrix}
X_1  \\
X_2  \\
\vdots{}\\
X_n
\end{bmatrix}
\end{equation*}
\qquad
\qquad
\quad
\quad
\quad
\quad
Y\ =\ 
\begin{bmatrix}
Y_1 \\
Y_2 \\
\vdots \\
Y_m
\end{bmatrix}
$$
- Multivariate Mean
	- The mean can be calculated in the same way, but on a per element basis : 
		-  $$\begin{equation*}
X = 
\begin{bmatrix}
X_1  \\
X_2  \\
\vdots{}\\
X_n
\end{bmatrix}
\end{equation*}
\quad
\quad
\quad
\quad
\quad
\quad
\bar{X}\ =\ E(X)\ = 
\begin{bmatrix}
E(X_1) \\
E(X_2) \\
\vdots \\
E(X_n)
\end{bmatrix}
$$
- Multivariate Covariance
	- The covariance between two random variable vectors can be calculated, which now forms a matrix of covariance values : 
		- $$\begin{equation*}
X = 
\begin{bmatrix}
X_1  \\
X_2  \\
\vdots{}\\
X_n
\end{bmatrix}
\end{equation*}
\quad

C_{XY}\ =\ E[(X-\bar X)(Y-\bar Y)^T]\ =E(XY^T)-\bar X\bar Y^T 
$$$$
Y\ =\ 
\begin{bmatrix}
Y_1 \\
Y_2 \\
\vdots \\
Y_m
\end{bmatrix}
\qquad
C_{XY}=
\begin{bmatrix}
C_{X_1Y_1}&C_{X_1Y_2}&\cdots &C_{X_1Y_m} \\
C_{X_2Y_1}&C_{X_2Y_2}&\cdots &C_{X_2Y_m} \\
\vdots & \vdots & \ddots &\vdots \\
C_{X_nY_1}&C_{X_nY_2}&\cdots &C_{X_nY_m} \\
\end{bmatrix}
$$
- Autocorrelation Matrix
	- The autocorrelation matrix, is simply the covariance matrix for the random vector and itself : 
		- $$C_X = E[(X-\bar X)(X-\bar X)^T]$$
		- $$C_{X}=
\begin{bmatrix}
\sigma ^2_{X_1}&\sigma _{X_1X_2}&\cdots &\sigma _{X_1X_n} \\
\sigma _{X_2X_1}&\sigma^2 _{X_2}&\cdots &\sigma _{X_2X_n} \\
\vdots & \vdots & \ddots &\vdots \\
\sigma _{X_nX_1}&\sigma _{X_nX_2}&\cdots &\sigma^2 _{X_n} \\
\end{bmatrix}$$
		-  $\sigma^2_{X_1}$ , $\sigma^2_{X_2}$ , $\cdots$ ->Variances         $\sigma^2_{X_1X_n}$ , $\cdots$ -> Cross-Covariances 
			- Properties 
				- Symmetric
					- $\sigma_{ij}=\sigma_{ji}$ , $C_x = C_x^T$
				- Positive Semidefinite 
					- $z^T C_Xz \ge 0$    


#### Gaussian Probability  $X \sim N(\mu,\sigma^2)$
- **$f_X(x)=\frac{1}{\sigma \sqrt{2\pi}}e^{-\frac{1}{2}(\frac{x-\mu}{\sigma})}$

	- ![[Pasted image 20240310150754.png]]
	- $P(\mu -1\sigma \le X \le \mu +1\sigma)=0.68$
	- $P(\mu -2\sigma \le X \le \mu +2\sigma)=0.95$
	- $P(\mu -3\sigma \le X \le \mu +3\sigma)=0.99$
- Multivariate Gaussian Distribution 
	- Random Variable : 
		- $X \sim N(\mu , \sigma^2)\qquad\qquad\qquad f_X(x)=\frac{1}{\sigma\sqrt{2\pi}}e^{-\frac{1}{2}(\frac{x-\mu}{\sigma})^2}$ 
	- Random Vector : 
		- $X \sim N(\bar{X} , C_X)\qquad\qquad\qquad f_X(x)=\frac{1}{(2\pi)^{\frac{1}{2}}\lvert{C_X}\lvert^{{1/2}}}e^{-\frac{1}{2}(X-\bar{X})^TC_X^{-1}(X-\bar{X})}$
	- The mean shifts the centre of the distribution, the variance controls the spread in the different axes, while the cross-covariances control the orientation of the distribution 


#### Linear Transformation of Uncertainties

- Transformation of Random Variables 
	- Random variables can be transformed through a function. Suppose we have a random variable X and its associated pdf $f_x(x)$, it is possible to apply a mathematical function $y=g(x)$ to the pdf and find the pdf $f_Y(y)$ of the transformed random variable $Y$.
	- Assume the transformation function are monotonic
		- $y=g(x)$
		- $x=g(y)^{-1}=h(y)$
		- $$f_Y(y)=\lvert h'(y)\lvert f_X(h(y))$$
- Linear Transformation of Gaussian PDF
	- Suppose we have the random variable : 
		- $X\sim N(\bar x,\sigma ^2_x)$
		- $f_X(x)=\frac{1}{\sigma_x\sqrt{2\pi}}exp(-\frac{1}{2}(\frac{x-\bar x}{\sigma_x})^2)$
	- Suppose we have the  transformation :
		- $Y=g(X)=aX+b$
		- $X=g^{-1}(Y)=\frac{Y-b}{a}$
		- $h(Y) = \frac{Y-b}{a}$
		- $h'(y) = \frac{1}{a} \longrightarrow$using the relationship : $f_Y(y)=\lvert h'(y)\lvert f_X(h(y))$
		- We find : 
			- $f_Y(y)=\frac{1}{\alpha\sigma_x\sqrt{2\pi}}exp[-\frac{1}{2}(\frac{y-(\alpha \bar x + b)}{\alpha \sigma_x})^2]$
	- A linear transformation of a Gaussian PDF is just another Gaussian PDF with the mean and  variance transformation 
		- $X\sim N(\bar x , \sigma^2_x)\longrightarrow Y=a X + b \longrightarrow Y \sim N(a \bar x +b,a^2\sigma^2_x)$
- Linear Transformation of Multivariate Gaussian Distribution 
	- Suppose we have the random vector :
		- $X\sim N(\bar x,C_X)$
	- Suppose we have the transformation : 
		- $Y=g(X)=AX+b$
		- $X=g^{-1}(Y)=A^{-1}Y-A^{-1}b$
		- $h(Y)=A^{-1}Y-A^{-1}b$
		- $h'(y)=A^{-1}$
		- Using the relationship : $f_Y(y)=\lvert h'(y)\lvert f_X(h(y))$
		- We find : $f_Y(Y)=\frac{1}{(2\pi)^{n/2} \lvert AC_X A^T  \lvert ^{1/2}}e^{-1/2(Y-\bar Y)^T(AC_XA^T)^{-1}(Y-\bar Y)}$
			-  $\bar Y \longrightarrow$ $A\bar X +b$ , $C_Y \longrightarrow$ $AC_XA^T$
	- A linear transformation of a Gaussian PDF is just another Gaussian PDF with the mean and variance transformed
		- $X\sim N(\bar x,C_X)\longrightarrow Y=AX+b \longrightarrow Y\sim N(A\bar X + b , AC_X A^T)$
	- If $C_X$ represents the uncertainty covariance, then it can be transformed to another frame using the linear transform $y=Ax$ where the transformed covariance is given by $C_Y = AC_XA^T$
#### State Space Representation 

- A system is a collection of interrelated entities (or different  equations) that can be considered as a whole 
- If the different process that make up this system change with time, then it is considered as a **dynamic system**
- The differential equations that make up the system are the **state equations** of the dynamic system. The **state variables** of the system are the **dependent variables** of the state equations.
- Consider the system of time varying, first-order differential equations :  $\dot x = \frac {dx}{dt}$
	 $\dot x_1 = f_1(t,x_1,x_2,\cdots,x_n,u_1,u_2,\cdots,u_m)$
	 $\dot x_2 = f_2(t,x_1,x_2,\cdots,x_n,u_1,u_2,\cdots,u_m)$
	 $\dot x_3 = f_3(t,x_1,x_2,\cdots,x_n,u_1,u_2,\cdots,u_m)$
	 $\quad\quad \vdots$
	 $\dot x_n = f_n(t,x_1,x_2,\cdots,x_n,u_1,u_2,\cdots,u_m)$
	 
	 $\dot x_n \rightarrow$ n-state equations         
	 $t \rightarrow$ Time Varying
	 $x_1,x_2,\cdots,x_n\rightarrow$ n - States
	 $u_1,u_2,\cdots,u_n\rightarrow$ m - Inputs
	  
	 - This can compactly be written as : 
		 $\dot x(t) = f(t,x(t),u(t))$
		 where : 
			 State Vector $x(t) = [x_1(t),x_2(t),\cdots,x_n(t)]^T$
			 Input Vector $u(t) = [u_1(t),u_2(t),\cdots,u_n(t)]^T$
-  Many of the processes that occur in the world can be expressed as linear or non-linear differential equations
- We can describe these processes in state-space form which then allow us to use different **mathematical tools** to extract useful information and perform various analysis on the system 
- If the know the state of the system for the current time and all the current and future inputs to that system, then we can predict the values of the future states and outputs of that system and a lot more.

#### Mathematical Models

- ![[Screenshot from 2024-03-10 23-11-04.png]]
- Continuous Non-Linear Model       $\dot x = f(t,x(t),u(t))$
	- $\dot x(t) = f(t,x(t),u(t))$ 
	 Continuous Time -> $\dot x(t)$          General Function --> $f$      
	 Time Varying --> $t$
- Continuous Linear Model
	$\dot x(t) = A(t)x(t) + B(t)u(t)$
	 Continuous Time -> $\dot x(t)$                
	 Time Varying --> $t$                    Linear Function $A(t)x(t)$
	 $$
\begin{bmatrix}
\dot x_1(t) \\
\dot x_2(t) \\
\vdots \\
\dot x_n(t)
\end{bmatrix}\ =\ 
\begin{bmatrix}
a_{11}(t)&a_{12}(t)&\cdots &a_{1n}(t) \\
a_{21}(t)&a_{22}(t)&\cdots &a_{2n}(t) \\
\vdots & \vdots & \ddots &\vdots \\
a_{n1}(t)&a_{n2}(t)&\cdots &a_{nn}(t) \\
\end{bmatrix}
\begin{bmatrix}
x_1(t) \\
x_2(t) \\
\vdots \\
x_n(t)
\end{bmatrix}
+
\begin{bmatrix}
b_{11}(t)&b_{12}(t)&\cdots &b_{1r}(t) \\
b_{21}(t)&b_{22}(t)&\cdots &b_{2r}(t) \\
\vdots & \vdots & \ddots &\vdots \\
b_{n1}(t)&b_{n2}(t)&\cdots &b_{nr}(t) \\
\end{bmatrix}
\begin{bmatrix}
u_1(t) \\
u_2(t) \\
\vdots \\
u_r(t)
\end{bmatrix}
$$
- Discrete Non-Linear Model
	$x_{k+1} = f(t_k,x_k,u_k)$
	Discrete Time -> $k+1$          General Function --> $f$      
	Time Varying --> $k$ 
- Discrete Linear Model
	$x_{k+1} = F_kx_k + G_ku_k$
	Discrete Time --> $k+1$         
	Time Varying --> $k$                  Linear Function $F_kx_k$
	$$
\begin{bmatrix}
x_1 \\
x_2 \\
\vdots \\
x_n
\end{bmatrix}_{k+1}\ =\ 
\begin{bmatrix}
f_{11}&f_{12}&\cdots &f_{1n} \\
f_{21}&f_{22}&\cdots &f_{2n} \\
\vdots & \vdots & \ddots &\vdots \\
f_{n1}&f_{n2}&\cdots &f_{nn} \\
\end{bmatrix}_{k}
\begin{bmatrix}
x_1 \\
x_2 \\
\vdots \\
x_n
\end{bmatrix}_{k}
+
\begin{bmatrix}
g_{11}&g_{12}&\cdots &g_{1r} \\
g_{21}&g_{22}&\cdots &g_{2r} \\
\vdots & \vdots & \ddots &\vdots \\
g_{n1}&g_{n2}&\cdots &g_{nr} \\
\end{bmatrix}_{k}
\begin{bmatrix}
u_1 \\
u_2 \\
\vdots \\
u_r
\end{bmatrix}_{k}
$$
--------------------------------------------------------
                Continuous                                      Discrete

----------------------------------------------------------
Time Varying

General                $\dot x(t) = f(t,x(t),u(t))$                    $x_{k+1} = f(t_k,x_k,u_k)$

Linear                   $\dot x(t) = A(t)x(t) + B(t)u(t)$          $x_{k+1} = F_kx_k + G_ku_k$

Time Invariant

General                $\dot x(t) = f(x(t),u(t))$                    $x_{k+1} = f(x_k,u_k)$

Linear                   $\dot x(t) = Ax(t) + B(t)u(t)$          $x_{k+1} = Fx_k + G_ku_k$

--------------


#### Discrete Time Conversions

- Continuous System
	- Continuous, Time Invariant, Linear system
		- $\dot x(t)=Ax(t)+Bu(t)$
	- Solution
		- $x(t)= e^{A(t+t_0)}x(t_0) + \int _{t_0}^te^{A(t-\tau)}Bu(\tau)d\tau$ 
	- Consider a Discrete Time Step : 
		- Current Time Step : $t=t_k$
		- Previous Time Step : $t_0=t_{k-1}$
		- Time Step Size : $\Delta t=t_k-t_{k-1}$
	- $x(t_k)=e^{A\Delta t}x(t_{k-1})+e^{A\Delta t}\int_0^{\Delta t}e^{-A\alpha}d\alpha Bu(t_{k-1})$
- Continuous to Discrete Conversion
	- $x(t_k)=e^{A\Delta t}x(t_{k-1})+e^{A\Delta t}\int_0^{\Delta t}e^{-A\alpha}d\alpha Bu(t_{k-1})$ --> $x_k = Fx_{k-1}+Gu_{k-1}$
	 $F=e^{A\Delta t}$
	 $G=F\int_0^{\Delta t}e^{-A\alpha}d\alpha B$
	    $=F[I-e^{-A\Delta t}]A^{-1}B$  if  $A^{-1}$ exist
- Matrix Exponential
	 $e^{At}=\sum_{j=0}^\infty \frac{(At)^j}{j!}$
	 $e^{At}=(At)^0+(At)^1+\frac{(At)^2}{2!}+\frac{(At)^3}{3!}+\cdots$
		  $$
\begin{equation}
\boxed{
\begin{array}{cl}
First Order Approximation:\ \ \\
e^{At}\approx I+At
\end{array}
}
\end{equation}
$$


$$P_{rvi} =

\begin{bmatrix}
 x_{RVi} \\
y_{RVi} \\
\phi_{RVi}
\end{bmatrix}\ =\ 
\begin{bmatrix}

cos(90 - \psi_{HV})&sin(90-\psi_{HV})&0\\
-sin(90 - \psi_{HV})&cos(90-\psi_{HV})&0\\
0&0&1
\end{bmatrix}
\begin{bmatrix}
k_{long}(\lambda_{RVi}-\lambda_{HV})\\
k_{lay}(\phi_{RVi-\phi_HV})\\
\psi_{RVi}-\psi_{HV}
\end{bmatrix}
$$
$$
k_{long} = \pi a cos(archtan(r*tan(\phi_{HV})))
k_{lat} = 111132.954 - 559.822 * cos(2*\phi_{HV})+1.175 *cos(4*\phi_{HV})
a = 6378137 
r = .996647

\lambda is the longitudinal angle
\phi is the lateral angle
\psi is the heading angle

HV is host vehicle 
RV remote vehicle

$$