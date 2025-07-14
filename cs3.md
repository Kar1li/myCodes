
The development and operation were not as plain sailing as 
expected, or rather, exceptions and problems were the routine. There 
were three major issues worth discussing.

The first issue was the performance degraded of the ticket 
system due to unknown reasons. After several weeks of the 
deployment of the system, on some day and afterward, the 
web witnessed severe lagging periodically at random intervals. Most of 
the time, the system performed as normal as usual. However, 
some clicks took extremely long time for responses, which was 
rather annoying to user experience.

The second issue was a crisis caused by my improper
behaviour of conducting database query. One field of the ticket 
was initially of the format of HTML. After days of 
operation, the contents of this field tended to be stable 
and relatively fixed. It was better to strip those HTML 
tags to save storage. Terribly, my SQL sentences mistakenly overwrite 
all other fields instead of the desired one, causing severe 
data loss.


----

My role as a problem solver and crisis handler was therefore 
brought forth. To resolve a problem, the first thing was 
naturally to find out its causes and roots, which required 
my professional skills of analysis and reasoning. If the root 
cause could be found, actions would be directly applied to 
solve the issus. If not, I needed to design alternative 
remedies to alleviate the symptom.

As for the database issue, the problem was more
than clear. I would have to apply my crisis handling 
skills to try my best to make up for the 
loss while looking for possible opportunities to reverse the situtaion 
for my interest.

----

The beginning of my problem solving was to recall any 
possibly related events that caused the issue. I firstly suspected 
that it was the code modification to the hiding of 
email input in the ticket open page that led to 
the lagging. I applied the knowledge of version control learned 
in the school to roll back to the version before 
the modification. The problem persisted.

The next skill I used for this issue was the 
breakpoint test. I deliberately clicked everywhere in an attempt to 
reproduce the problem trying to find the pattern of occurrence.
Finally, I observed that all steps proceeded fastly except for 
the ones carrying out database query. I discovered that the root 
was in the database. Checking out its performance statistics proved 
my conjecture. Increasing its buffer in the memory of the 
VM resolved the issus.

----

In fact, the resolving process was not as smooth as 
I wrote it to be. My insufficient knowledge about the 
operating system and server produced a lot of uncertainties which 
confused and distracted me from the right way to the 
root cause. The approach I adopted was workplace communication. No 
one was expected to do everything on their own. That 
was why we formed groups to co-operate. I sent an 
email to a colleague for help and he replied quickly 
to locate the problem with information I tested out.

Similarly to the striping crisis, despite my effort to 
restore most of the data, all phone numbers were gone. 
I had no choice but to acknowledge my mistakes and 
plead for assistance. Fortunately, my apology was kindly accepted and 
the data were gradually found with their help.

----

These experiences served as valuable lessons to me the importance 
of preservation. In computer science courses, I was taught about 
concepts of version control and backup. Back then, I made 
little sense about them and only deemed them tedious and 
unnecessary to pay attention to. After the incidents, I got 
to know that they were of tremendous significance as your 
life could be saved with their very presence.

The essence of both version control and backups are to 
preserve a copy before moving on to make changes especially 
dangerous ones involving deletion. The git repository showed me its 
ability to save my effort to repeatedly add and cut
codes while the absence of backup of the database table 
trapped me into the disaster of struggling to collect every 
scattered pieces of data all over the world to compensate 
for a missing condition in the SQL query.
