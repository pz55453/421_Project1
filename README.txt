
Since I was not able to finish the project, I will explain 
what I was able to get done and my understanding of this.

I was able to create 10 child procesess using fork(). Next, 
I created a log file where I indicated when each process
was created and terminated. I made each child live for five
minutes, however this did not allow me to keep all the children
alive at the same time. Without keeping them alive for 5 
minutes I was able to keep them alive at the same time
(concurrent programming). But once I kept hthem alive for
5 minutes I could not keep them alive at the same time.
One would start and the next would have to wait for the 
previous one to finish and then the second one would start.

I also created a client.c and a server.c.
If you run both of this individually, running server.c first
and then running client.c, the client receives the data from
the server. These files represent the socket which I was
not able to include in my ParentProcess.c file. Als, I made
an attemp at writing a Makefile but I was not able to 
complete it. Thus, each file has to be compiled individually.

I started to understand how this project really works close
to the due date which is why I was not able to complete it.
