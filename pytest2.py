import threading
import time

class myThread (threading.Thread):
    def __init__(self, threadID, name, counter,lock):
        threading.Thread.__init__(self)
        self.threadID = threadID
        self.name = name
        self.counter = counter
        self.lock=lock
    def run(self):
        print "Starting " + self.name
        # Get lock to synchronize threads
        self.lock.acquire()
        print_time(self.name, self.counter, 3)
        # Free lock to release next thread
        self.lock.release()

def print_time(threadName, delay, counter):
    while counter:
        #time.sleep(delay)
        print "%s: %s" % (threadName, time.ctime(time.time()))
        counter -= 1

threadLock=threading.Lock()
threads = []

# Create new threads
thread1 = myThread(1, "Thread-1", 1,threadLock)
thread2 = myThread(2, "Thread-2", 2,threadLock)

# Start new Threads
thread1.start()
thread2.start()
# Add threads to thread list
threads.append(thread1)
threads.append(thread2)

# Wait for all threads to complete
for t in threads:
    t.join()
print "Exiting Main Thread"
