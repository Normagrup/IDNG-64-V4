unsigned char daliUtilsBootloaderModelHSet(unsigned char dest,unsigned char data);
unsigned char daliUtilsBootloaderModelLSet(unsigned char dest,unsigned char data);
unsigned char daliUtilsBootloaderVersionSet(unsigned char dest,unsigned char data);
unsigned char daliUtilsBootloaderStatusSet(unsigned char dest,unsigned char data);
unsigned char daliUtilsBootloaderModelHGet(unsigned char dest, unsigned char *valid, unsigned char *answer);
unsigned char daliUtilsBootloaderModelLGet(unsigned char dest, unsigned char *valid, unsigned char *answer);
unsigned char daliUtilsBootloaderVersionGet(unsigned char dest, unsigned char *valid, unsigned char *answer);
unsigned char daliUtilsBootloaderStatusGet(unsigned char dest, unsigned char *valid, unsigned char *answer);
unsigned char daliUtilsBootloaderWritePage(unsigned char *pageContent);
unsigned char daliUtilsRebootSend (unsigned char dest);
void daliUtilsDoTask (void);
unsigned char daliUtilsBlinkSend (unsigned char dest, unsigned int period);
void daliUtilsDaliNotifyCb(unsigned int daliSentSenderPacketId, unsigned char daliSentFrameType, unsigned char daliSentDest, unsigned char *daliSentApply, unsigned char daliSentCommandHigh, unsigned char daliSentCommandLow, unsigned char daliReplyFrameType, unsigned char daliReplyValid, unsigned char *daliReplyValidArray, unsigned char daliReplyAnswer, unsigned char *daliReplyAnswerArray);									