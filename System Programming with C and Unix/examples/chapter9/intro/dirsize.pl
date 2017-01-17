# An example perl shell script (pg 302)
#
@filenames=<*>;
$count=@filenames;
if ($count > 5) {
  print "Large directory\n";
}
else {
  print "Small directory\n";
}
