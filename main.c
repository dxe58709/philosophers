/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:51:17 by nsakanou          #+#    #+#             */
/*   Updated: 2023/11/11 17:47:03 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

// int main() {
//     struct timeval currentTime;

//     // gettimeofday 関数を使用して現在の時刻を取得
//     if (gettimeofday(&currentTime, NULL) != 0) {
//         perror("gettimeofday");
//         return 1; // エラーコード
//     }

//     // 取得した時刻を表示
//     printf("Seconds: %ld\n", currentTime.tv_sec);
//     printf("Microseconds: %d\n", currentTime.tv_usec);

//     return 0;
// }


// スレッドが実行する関数
// void *threadFunction(void *arg) {
//     printf("This is the thread function.\n");
//     return NULL;
// }

// int main() {
//     pthread_t myThread; // スレッドの識別子
//     int result;

//     // pthread_create 関数を使用して新しいスレッドを作成
//     result = pthread_create(&myThread, NULL, threadFunction, NULL);
//     if (result != 0) {
//         perror("pthread_create");
//         return 1; // エラーコード
//     }

//     printf("Main thread continues to run.\n");

//     // スレッドの終了を待つ（実際のアプリケーションでは通常必要）
//     result = pthread_join(myThread, NULL);
//     if (result != 0) {
//         perror("pthread_join");
//         return 1; // エラーコード
//     }

//     printf("Main thread exiting.\n");

//     return 0;
// }

// void *threadFunction(void *arg) {
//     // スレッドが実行する処理...
//     printf("Thread is running.\n");
//     return NULL;
// }

// int main() {
//     pthread_t myThread;
//     int result;

//     // スレッドをデタッチ
//     result = pthread_create(&myThread, NULL, threadFunction, NULL);
//     if (result != 0) {
//         perror("pthread_create");
//         return 1; // エラーコード
//     }

//     result = pthread_detach(myThread);
//     if (result != 0) {
//         perror("pthread_detach");
//         return 1; // エラーコード
//     }

//     printf("Main thread continues to run.\n");

//     // ここで明示的にスレッドの終了を待たなくてもよい

//     return 0;
// }


pthread_mutex_t mutex; // ミューテックス
int sharedVariable = 0; // 共有変数

void *threadFunction(void *arg) {
    for (int i = 0; i < 10000; ++i) {
        // クリティカルセクションに入る前にミューテックスをロック
        pthread_mutex_lock(&mutex);

        // 共有変数にアクセス
        sharedVariable++;

        // クリティカルセクションから出るときにミューテックスをアンロック
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // ミューテックスの初期化
    pthread_mutex_init(&mutex, NULL);

    // 2つのスレッドを作成
    pthread_create(&thread1, NULL, threadFunction, NULL);
    pthread_create(&thread2, NULL, threadFunction, NULL);

    // スレッドの終了を待つ
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // ミューテックスの解放
    pthread_mutex_destroy(&mutex);

    // 共有変数の最終値を表示
    printf("Shared variable value: %d\n", sharedVariable);

    return 0;
}