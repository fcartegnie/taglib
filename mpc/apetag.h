/***************************************************************************
    copyright            : (C) 2004 by Allan Sandfeld Jensen
    email                : kde@carewolf.org
 ***************************************************************************/

/***************************************************************************
 *   This library is free software; you can redistribute it and/or modify  *
 *   it  under the terms of the GNU Lesser General Public License version  *
 *   2.1 as published by the Free Software Foundation.                     *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful, but   *
 *   WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
 *   Lesser General Public License for more details.                       *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this library; if not, write to the Free Software   *
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  *
 *   USA                                                                   *
 ***************************************************************************/

#ifndef TAGLIB_APETAG_H
#define TAGLIB_APETAG_H

#include "tag.h"
#include "tbytevector.h"

namespace TagLib {

  class File;

  //! An APE tag implementation

  namespace APE {

    class Tag : public TagLib::Tag
    {
    public:
      /*!
       * Create an APE tag with default values.
       */
      Tag();

      /*!
       * Create an APE tag and parse the data in \a file with APE footer at
       * \a tagOffset.
       */
      Tag(File *file, long tagOffset);

      /*!
       * Destroys this Tag instance.
       */
      virtual ~Tag();

      /*!
       * Renders the in memory values to a ByteVector suitable for writing to
       * the file.
       */
      ByteVector render() const;

      /*!
       * Returns the string "APETAGEX" suitable for usage in locating the tag in a
       * file.
       */
      static ByteVector fileIdentifier();

      /*!
       * Returns the size of the tag calculated based on the footer.
       */
      static uint tagSize(ByteVector footer);

      // Reimplementations.

      virtual String title() const;
      virtual String artist() const;
      virtual String album() const;
      virtual String comment() const;
      virtual String genre() const;
      virtual uint year() const;
      virtual uint track() const;

      virtual void setTitle(const String &s);
      virtual void setArtist(const String &s);
      virtual void setAlbum(const String &s);
      virtual void setComment(const String &s);
      virtual void setGenre(const String &s);
      virtual void setYear(uint i);
      virtual void setTrack(uint i);

      /*!
       * Removes the \a key comment from the tag
       */
      void removeComment(const String &key);

      /*!
       * Adds the \a key comment with \a value
       */
      void addComment(const String &key, const String &value);

    protected:
      /*!
       * Reads from the file specified in the constructor.
       */
      void read();
      /*!
       * Parses the body of the tag in \a data with \a count items.
       */
      void parse(const ByteVector &data, uint count);

    private:
      Tag(const Tag &);
      Tag &operator=(const Tag &);

      class TagPrivate;
      TagPrivate *d;
    };
  }
}

#endif
