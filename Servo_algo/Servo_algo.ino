long NextMove;

int MoveDelay; ’ the number of milliseconds between each step, smaller steps = faster movement

int Step; ’ the amount the servo moves with each loop, keep this number small

int TargetPosition; ’ this controls where the joint is moving to, you just change the targetposition to make it move

loop(){

   if millis() >= NextMove and JointPosition <> TargetPosition then MoveJoint;

}

MoveJoint() {

   Int NewPosition = CurrentPosition + Step;

   rem the next two lines make sure you don’t overshoot the target

   If CurrentPosition < TargetPosition and NewPosition > TargetPosition then NewPosition = TargetPosition;

   if CurrentPosition > TargetPosition and NewPosition < TargetPosition then NewPosition = TargetPosition;

   Joint.move(NewPosition);

   CurrentPosition = NewPosition;

   NextMove = millis() + MoveDelay;

}
