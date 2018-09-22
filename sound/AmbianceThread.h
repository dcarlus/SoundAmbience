#ifndef AMBIANCETHREAD_H
#define AMBIANCETHREAD_H

#include "Ambiance.h"
#include <QThread>
#include <memory>

class AmbianceModel;

///
/// \brief  Thread used to play a sound ambiance.
///
class AmbianceThread final : public QThread
{
    Q_OBJECT

    private:
        ///
        /// \brief  true if the thread is running; false otherwise.
        ///
        bool m_running = false;

        ///
        /// \brief  Sound ambiance that is played while the thread is running.
        ///
        std::unique_ptr<Ambiance> m_ambiance;

    public:
        ///
        /// \brief  Create the thread.
        /// \param  model   Model of the ambiance to generate.
        ///
        AmbianceThread(const AmbianceModel& model);

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

#endif // AMBIANCETHREAD_H
