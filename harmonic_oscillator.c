/*damped harmonic oscillator
with all 3 real cases */  

    /*there will be 3 cases 1st one will have imaginary root,

    >> "sol for critically damped H.Osc is ,x(t)={x0*exp^-(b/2m)t}cosw, where w=sqrt((k/m)-((b*b)/(4*m))),E=exp^-(b/2m)t"
     two will have real roots,

    >> "sol for over damped under damped cases is ,x(t)=x0/2[exp(ROOT1t)+exp(ROOT2t)]" */ 

    /*now we will define all the variables that we will use later*/ 

#include<stdio.h>
#include<math.h>

int main () 
{
      float u,                                                        //coefficient of friction 
            k,                                                        //spring constant 
            m,                                                        //mass of the object 
            x0,                                                       //initial position of the mass 
            t,                                                        //for time 
            xt,                                                       //position after time t 
            ROOT1t, ROOT2t,		                                      //roots of the quadratic eq
            e = 2.71828, P1, P2,                                       
            P, i,	                                                  //i is max time
            n,				                                          //for no of observation within time
            r1, r2, c_4ac, b_sr, ru,	                              //these variables will help to compare the 3 cond.
            a = 1, b, c,                              
            w, q, E, cosw;	                                          //these variable are only for simplifying calculations
     
    while (1) 
    { 
        printf ("enter value of u k & m serially: eg: 8 15 4\n");	  //here parameters are provided by the user
        scanf ("%f%f%f", &u, &k, &m);
        
        if (u == 0 && k == 0 && m < 0)
        {    
            printf ("Incorrect Values: Enter u !=0, k!=0, m>0\n");
            continue;
        }
        else
            break;
    }
    
    b = u / m, c = k / m;
    printf ("\na=%f,b=%f,c=%f\n", a, b, c);
    c_4ac = 4 * a * c;
    b_sr = b * b;
    
    if (c_4ac > b_sr)		                                           //condition for complex roots 
    {
        printf ("\nroots are complex\n");
        printf ("\nprovide following values to see , CRITICAL DAMPING\n");

        while (1)
        {
        	printf ("\nenter the value of x0,t and and n(for no of observations you want): eg: 3 10 100\n");
            scanf ("%f%f%f", &x0, &i, &n);	                            //the maximum pull and the time up to which we want to study motion
        	
            if (x0 != 0 && i > 0 && n > 0)
                break;
        	else
        	{    
                printf ("Enter x0 !=0, t>0, n>0\n");
                continue;
            }
        }
        
        for (t = 0; t <= i; t = t + (i / n))	                        //here i have set the counter so that it will give 100 small increment of time starting from 0
        {     
            w = (sqrt ((k / m) - ((b * b) / (4 * m))));
            cosw = cos (w*t);
            q = -(b / (2 * m)) * t;
            E = pow (2.71828, q);
            xt = E * x0 * cosw;
            printf ("\nxt=%f   t=%f\n \n", xt, t);
        }
    }
    else if (c_4ac < b_sr)	                                            //condition for real roots 
    {    
        r1 = (-b + (sqrt (b_sr - c_4ac))) / 2 * a;
        r2 = (-b - (sqrt (b_sr - c_4ac))) / 2 * a;
        printf ("ROOT1=%f\nROOT2=%f", r1, r2);
        printf ("provide following values to see ,UNDER DAMPING");
    }
    else if (c_4ac == b_sr)	                                            //condition for unique and single root 
    {    
        ru = -b / 2 * a;
        printf ("\nONLY ONE ROOT=%f\n", ru);
        printf ("\nprovide following values to see ,HEAVY DAMPING\n");
    }
    printf ("\nprovide maximum displacement of m ,t and n(for no of observations you want)\n");
    scanf ("%f%f%f", &x0, &i, &n);
    for (t = 0; t <= i; t = t + (i / n))	                        //here i have set the counter so that it will give 100 small increment of time starting from 0
    {    
        ROOT1t = r1 * t, ROOT2t = r2 * t;
        P1 = pow (e, ROOT1t), P2 = pow (e, ROOT2t);
        P = P1 + P2;
        xt = (x0 * 0.5) * P;
        printf ("\nxt= %f  t= %f\n", xt, t);
    }
}


    
    
