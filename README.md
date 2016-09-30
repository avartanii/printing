**CMSI 370** Interaction Design, Fall 2016

# Group Chat Usability Study

- Anson Adams
- Anthony Escobar
- Harris Lummis
- Allen Vartanian
- Andres Lazo

## Study Description

The systems compared were the desktop applications for HipChat and Slack. These applications were chosen because of their similar functionalities and purposes, as well as because we anticipated a large number of users would be unfamiliar with them and therefore viable for learnability testing.

Chosen tasks:

- Task 1: Create a new channel/room called "usability survey" and set its purpose/topic to "best survey ever"
- Task 2: Add someone to the current chat by their email address.
- Task 3: Change the current user's profile picture/avatar to an existing photo.

Chosen Metrics:

- Metric 1: Learnability. For each task, we give a short explanation of the task the participant should accomplish. We restrict our explanation to general verbal tasks, such as "create a new group chat," and do not give technical details. Then, we ask the participant to complete the requested task using the application and verbalize their thinking method. We time how long the task took to complete successfully and record audio so to understand how the participant percieves their interactions with the application. We note how many errors were made in the attempt to complete each task.
- Metric 2: Efficiency. First, the participant fully learns how to complete each of the three tasks and demonstrates they can complete the tasks free of errors. Then, we ask the participant to complete each task as quickly as possible without making errors, timing how long each individual task takes to complete successfully.
- Metric 3: Satisfaction. After each survey is conducted, we ask study participants to rate their overall level of satisfaction with using each application on a level from 1 (no satisfaction or enjoyment) to 10 (high level of satisfaction and enjoyment).

## Study Results
Provide the data that were gathered from the study. Tables and graphs (as images) are recommended. Refrain from adding commentary or conclusions in this section, except for indications of what the data _directly_ indicate, such as which system performed better for which metric.

Raw files such as spreadsheets or notes may be added to this repository, if you wish.

## Heuristic Evaluation
Consult the [assignment writeup](README.md) for details on this section. Put all of that here.

### Task 1: Create a New Channel/Group

#### Slack

Notice in the Slack interface that the button responsible for initiating the "Create Channel" dialog is rendered in a low intensity color, drawing attention away from the button. This likely contributed to the lower learnability of Slack's channel creation function relative to Hipchat's. From the designer's perspective, the button's placement directly in the header for the "Channels" section makes perfect sense. The designers likely wanted to prioritize the visibility of active channels over the creation of new ones (accessing an existing channel would be a more commonly performed action), but ended up causing confusion among users.  

![Slack Create Channel] (/ScreenShots/Slack/Slack_Create_Channel.png)
*Figure 1.1: Slack's Create Channel button, highlighted in blue.*

Another likely contributing factor to Slack's poor relative learnability in terms of channel creation would be the requirement that the names of Slack channels cannot contain certain characters, a requirement that is in the below screenshot highlighted in red. Many users made the error of including forbidden characters, likely due to the low visibility of the requirement. These errors may be a result of differing utilities between Slack and HipChat, thus in later studies we would eliminate this variability by requiring users to enter a predetermined channel name. The developers likely did not want to make the requirements more prominent to avoid giving the user impression that they had done something improper when no such activity had yet occured. 

![Slack New Channel Dialog] (/ScreenShots/Slack/Slack_New_Channel_Dialog.png)
*Figure 1.2: Slack's create channel dialog, with nomenclature requirements highlighted in blue*

Figures 1.3 and 1.4 demonstrate two different error dialogs for improper channel names. Slack provides incomplete feedback regarding the requirements of the channel name. If a user enters a channel name with spaces, they will not be notified that uppercase characters are also forbidden and vice-versa. Notice how in the second pictured error that the user made two separate errors by including both uppercase characters and spaces, but would only be notified of the first error they made. The developers likely wanted to make error messages as concise as possible, but in doing so reduced the usefullness of the feedback provided to the user

![Slack New Channel Error 1] (/ScreenShots/Slack/Slack_New_Channel_Error_1.png)
*Figure 1.3: Error message for channel name containing space characters*

![Slack New Channel Error 2] (/ScreenShots/Slack/Slack_New_Channel_Error_2.png)
*Figure 1.4: Error message for channel name containing space and uppercase characters*

#### HipChat

HipChat displays two prominent buttons which users may interpret as instigators of the "Create Room" action. One of these is located in the upper left of the interface (see the button outlined in red in Figure 1.5). This button opens a dialog (pictured in Figure 1.6) wherein the user can start a chat with an existing teammate or within an existing room. A number of users confused this button for the actual "Create Room" button (outlined in blue in Figure 1.5), and still attempted to create a chat from within this dialog. The "New Chat" functionality would be useful to a more experienced user, but its name confuses newer users and provides little useful feedback in terms of misusing the function. Though the placement and visual prominence of the "Create Room" button made it relatively easy for users to find it, there was still much confusion between this button and the "New Chat" button. 

![HipChat Create Room] (/ScreenShots/HipChat/HipChat_Create_Room.png)
*Figure 1.5: Hipchat's "Create Room" and "New Chat" buttons, highlighted in light blue and red respectively*

![HipChat Create Room] (/ScreenShots/HipChat/HipChat_New_Chat_Error.png)
*Figure 1.6: HipChat's "New Chat" dialog*

HipChat allows for the creation of groups whose names include space and uppercase characters, and has a similar dialog to that of Slack. Nothing notable here.

![HipChat Create Room] (/ScreenShots/HipChat/HipChat_New_Room_Dialog.png)
*Figure 1.7: HipChat's "New Room" dialog*

### Task 2: Invite Teammates By Email

#### Slack

![Slack Invite No Errors] (/ScreenShots/Slack/Invite_People_No_Error.png)
![Slack Invite Others Error] (/ScreenShots/Slack/Slack_Invite_Others.png)

#### HipChat

![HipChat Invite Team] (/ScreenShots/HipChat/HipChat_Invite_Team.png)
![HipChat Invite Team 2] (/ScreenShots/HipChat/HipChat_Invite_Step_2.png)
![HipChat Invite Error] (/ScreenShots/HipChat/Hipchat_Invite_Error.png)

### Task 3: Change Profile Picture

#### Slack

![Slack Profile 1] (/ScreenShots/Slack/Slack_Profile menu_Step_1.png)
![Slack Profile 2] (/ScreenShots/Slack/Slack_Profile_Step_2.png)
![Slack Profile 3] (/ScreenShots/Slack/Slack_Profile_Step_3.png)
![Slack Profile 4] (/ScreenShots/Slack/Slack_Profile_Step_4.png)
![Slack Photo Select] (/ScreenShots/Slack/Slack_Select_Photo.png)

Feel free to add subsections to keep your analysis organized. Because different groups will have different choices for what to discuss, I can’t specify further specifics here. However, all groups _should_ have:

### Prioritization of Metrics
State the relative importance of each metric with respect to the tested systems. This prioritization is particularly useful for resolving “toss-ups” (i.e., situations where system A performs better at one metric but system B performs better at another). Needless to say, don’t prioritize at random; the chosen priorities should make sense for the systems that were tested.

### Usability Decision
Yes, take a stand. Make an explicit, informed decision on which system is more usable based on your testing and data. Explain your decision using a combination of the test results and your heuristic evaluation of the systems.

## Statement of Work
Again, see the [assignment writeup](README.md) for details. Your repository’s commit log will also inform our view of how well the study’s work was distributed across the team. To wit, one concrete thing _not_ to do is to designate a single group member as the “committer” or “typist” for the group. Everyone should be answerable for their contributions to the usability study, and part of this answerability is reflected in the act of _committing your own data and writing_ under your own GitHub username.

_Comments from users.
"It's weird that it opens up on the browser" (HC, choosing to edit the profile)
"I prefer changing profile picture in HC because it's similar to facebook."
"I don't like how they tried to mix facebook and AOL (HC interface)"


