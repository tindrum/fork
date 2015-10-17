Assignment 1:

Nikita Sadinidhi Vijayan
Daniel Henderson
Joshua Edmonds

Programming language: C++

Questions:
1. In the output of time, what is the difference between real, user, and sys times?
2. Which is longer: user time or sys time? Use your knoweldge to explain why.
   The user time is zero, or close to it, because the process is not running interactively.
   The system time is very small, since only a few system calls are being used.
   If the program was interactive, i.e. the user enters urls for each file he/she wants to
   download, the user time would be much greater than the system time.
3. When downloading the files above, which downloader finishes faster? Why do you think
that is?
   The parallel version runs faster with small file sizes. 
   When running in serial, the incoming bandwidth is not a factor, nor is task switching.
   The parallel version will saturate any incoming bandwidth.
   More importantly, task switching between download tasks will become overhead,
   and slow the overall process.
4. Repeat the experiment for 10 files (any reasonably large-sized files, e.g., 100 MB, will do).
Is the downloader in the previous question still faster? If not so, why do you think that
is?

