/* 
 * File:   line.hpp
 * Author: dariush
 *
 * Created on March 30, 2014, 12:37 AM
 */

#ifndef LINE_HPP
#define	LINE_HPP
#include "bootstrap.hpp"
namespace demo {
    /**
     * Line Information container
     */
    class line {
    private:
        /**
         * The line's #
         */
        size_t lineNo;
        /**
         * The line's actual content
         */
        string content;
        /**
         * The related source which line has fetched from
         */
        const void* related_source;
    public:
        /**
         * Construct a line instance
         * @param lineNo The line's number
         * @param content The line's actual content
         * @param _source The related source which line has fetched from
         */
        inline line(size_t lineNo, string content, const void*  _source = NULL) { this->__init(lineNo, content, _source); }
        /**
         * Construct a line instance from and other instance
         * @param orig the origin line instance
         */
        inline line(const line& orig)  { this->__init(orig.lineNo, orig.content, orig.related_source); }
        /**
         * Get line's content
         * @return the line's content
         */
        inline string getContent() const { return this->content; }
        /**
         * Get line's number
         * @return the line's number
         */
        inline size_t getLineNumber() const { return this->lineNo; }
        /**
         * Get the source which current line has fetched from
         * @return By dependecy and circular includes problem (void*) will return instead of (demo::source*)
         * @remark The output should `static_cast&lt;const demo::source*&gt;` and then used
         * &nbsp;&nbsp;as a `demo::source` instance.
         */
        inline const void* getSource() const { return this->related_source; }
        /** 
         * ToString() function of line class 
         */
        friend std::ostream & operator<<(std::ostream & _stream, line const & _line);
        /**
         * The == overloading
         */
        friend bool operator==(const line& lhs, const line& rhs);
        /**
         * The != overloading
         */
        friend inline bool operator!=(const line& lhs, const line& rhs){return !(lhs == rhs);}
    protected:
        /**
         * Initialize   this` line instance
         * @param lineNo The line's number
         * @param content The line's actual content
         * @param _source The related source which line has fetched from
         */
        line* __init(size_t lineNo, string content, const void*  _source);
    };
}

#endif	/* LINE_HPP */

