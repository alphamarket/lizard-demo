/* 
 * File:   line.cpp
 * Author: dariush
 * 
 * Created on March 30, 2014, 12:37 AM
 */

#include "line.hpp"
namespace demo {
    std::ostream & operator<<(std::ostream & _stream, line const & _line) { 
        /* output the line's content only */
        _stream << _line.getContent();
        /* return the streaming instance */
        return _stream;
    }
    bool operator==(const line& lhs, const line& rhs) {
        /* everything should match */
        return lhs.getLineNumber() == rhs.getLineNumber() &&
                lhs.getContent() == rhs.getContent() &&
                lhs.getSource() == rhs.getSource();
    }
    line* line::__init(size_t lineNo, string content, const void* _source) {
        /* init the line's no */
        this->lineNo = lineNo;
        /* init the line's content */
        this->content = content;
        /* init the related source */
        this->related_source = _source;
        /* return `this` instance */
        return this;
    }
}
