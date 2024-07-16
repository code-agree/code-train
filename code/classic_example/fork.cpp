#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>
#include <sys/wait.h>

std::mutex print_mutex;

void worker_thread(int id) {
    while (true) {
        std::lock_guard<std::mutex> lock(print_mutex);
        std::cout << "Thread " << id << " is running in process " << getpid() << std::endl;
        sleep(1);
    }
}

int main() {
    std::thread t1(worker_thread, 1);
    std::thread t2(worker_thread, 2);

    sleep(2);  // 让线程运行一会儿

    pid_t pid = fork();

    if (pid == 0) {  // 子进程
        std::cout << "Child process " << getpid() << " created." << std::endl;
        sleep(5);
        std::cout << "Child process exiting." << std::endl;
        exit(0);
    } else if (pid > 0) {  // 父进程
        std::cout << "Parent process. Child PID: " << pid << std::endl;
        int status;
        waitpid(pid, &status, 0);
        std::cout << "Child process exited." << std::endl;
    } else {
        std::cerr << "Fork failed!" << std::endl;
        return 1;
    }

    t1.join();
    t2.join();

    return 0;
}