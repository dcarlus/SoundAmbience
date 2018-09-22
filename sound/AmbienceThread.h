#ifndef AMBIENCETHREAD_H
#define AMBIENCETHREAD_H

#include "Ambience.h"
#include <QThread>
#include <memory>

class AmbienceModel;

///
/// \brief  Thread used to play a sound ambience.
///
class AmbienceThread final : public QThread
{
    Q_OBJECT

    private:
        ///
        /// \brief  true if the thread is running; false otherwise.
        ///
        bool m_running = false;

        ///
        /// \brief  Sound ambience that is played while the thread is running.
        ///
        std::unique_ptr<Ambience> m_ambience;

    public:
        ///
        /// \brief  Create the thread.
        /// \param  model   Model of the ambience to generate.
        ///
        AmbienceThread(const AmbienceModel& model);

        ///
        /// \brief  Stop the thread.
        ///
        void stop();

    protected:
        ///
        /// \brief Run the thread execution.
        ///
        virtual void run() final;
};

#endif // AMBIENCETHREAD_H
