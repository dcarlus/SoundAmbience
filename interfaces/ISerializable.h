#ifndef ISERIALIZABLE_H
#define ISERIALIZABLE_H

#include <QString>

///
/// \brief  Serializable class that can be saved/loaded from a file on disk.
///
class ISerializable
{
   public:
        ///
        /// \brief  Load data from a file.
        /// \param  path    Path to the file.
        ///
        virtual void load(const QString& path) = 0;

        ///
        /// \brief  Save data to a file.
        /// \param  path    Path to the file.
        ///
        virtual void save(const QString& path) = 0;
} ;

#endif // ISERIALIZABLE_H
