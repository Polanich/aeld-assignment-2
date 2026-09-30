/*
 * Title: writer.c
 * Author: justinp
 *
 */

#include <unistd.h>
#include <string.h>
#include <syslog.h>
#include <fcntl.h>

/*
 * Main program entry
 */ 
int main(int argc, char *argv[0])
{
   // Open the system log for the user
   openlog(NULL, 0, LOG_USER);

   // Validate the number of arguments
   if(argc != 3)
   {
      // Log invalid number of arguments and return 1
      syslog(LOG_ERR, "Invalid number of arguments: %d", argc);
      return 1;
   }
   
   char *writefile = argv[1];
   char *writestr = argv[2];
   
   // Create or open and truncate a file for writing
   // based on the name and path passed as an argument 
   int fd = creat(writefile, 0644);
   
   // Validate file
   if (fd == -1)
   {
      // Log the error and return 1
      syslog(LOG_ERR, "Error opening file: %m");
      return 1;
   }
   
   // Write string to the file
   size_t count = strlen(writestr);
   ssize_t nr = write(fd, writestr, count);
   
   // Validate write
   if (nr == -1)
   {
      // Log the error and return 1
      syslog(LOG_ERR, "Error writing to file %s: %m", writefile);
      return 1;
   }
   // Check for complete write
   else if (nr != count)
   {
      // Log the error and return 1
      syslog(LOG_ERR, "Partial write to file %s", writefile);
      return 1;
   }
   // All good
   else
   {
      // Log success message
      syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);
   }
   
   // Close the file
   if (close(fd) == -1)
   {
      syslog(LOG_ERR, "Error closing file %s: %m", writefile);
      return -1;      
   }
   
   // Program success
   return 0;
}
