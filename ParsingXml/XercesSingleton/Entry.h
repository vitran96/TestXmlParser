#ifndef XercesSingleton_H
#define XercesSingleton_H

#include <memory>

#include <string>

#include <vector>
#include <map>

namespace xercesc_3_2
{
    class DOMImplementation;
    class DOMDocument;
    class DOMElement;
    class DOMNode;
    // TODO: Add more?
}

class XmlDocument
{
private:
    std::shared_ptr<xercesc_3_2::DOMDocument> _xmlDocument;
    std::string _encoding;
public:
    XmlDocument();
    virtual ~XmlDocument();

    //
};

class XmlElement
{
private:
    std::shared_ptr<xercesc_3_2::DOMNode> _parentNode;
    std::shared_ptr<xercesc_3_2::DOMElement> _xmlElement;

    bool _assigned = false;
public:
    XmlElement(std::shared_ptr<xercesc_3_2::DOMDocument> emptyDOMDocument, std::string name);
    virtual ~XmlElement();

    bool IsAssigned() const;

    void SetText(const std::string &text);
    void SetAttribute(const std::string &key, const std::string &value);
    void SetAttributes(const std::map<std::string, std::string> &attributes);

    void SetParentNode(std::shared_ptr<xercesc_3_2::DOMNode> parentNode);

    std::string ToString() const;

    //bool operator==(...) const;
    //bool IsEqual(...) const;
};

class XercesAdapter
{
    //friend XmlDocument;
    //friend XmlElement;
private:
    XercesAdapter();
    //static void Initialize();
    //static void InitializeAdapter();
    void InitializeDomImplementation();

    void Clear();

    //static std::shared_ptr<XercesAdapter> _adapter;
    //static XercesAdapter * _adapter;

    /*static shared_ptr<Demo> getInstance() {
        static shared_ptr<Demo> d(new Demo);
        return d;
    }*/

    /*static Demo &getInstance() {
        static Demo d;
        return d;
    }*/

    std::shared_ptr<xercesc_3_2::DOMImplementation> _domImpl;
public:
    XercesAdapter(XercesAdapter const &) = delete;
    XercesAdapter& operator=(XercesAdapter const &) = delete;

    virtual ~XercesAdapter();

    static XercesAdapter& GetInstance();

    std::shared_ptr<xercesc_3_2::DOMDocument> CreateEmptyDocument() const;

    //
};

class XmlLib
{
private:
public:
    static std::shared_ptr<XmlDocument> CreateXmlDocument(XmlElement &rootNode, const std::string &version, const std::string &encoding, const bool &standalone);
    static std::shared_ptr<XmlElement> CreateXmlElement(const std::string &name, const std::string &text, const std::map<std::string, std::string> &attributes);
};

#endif // !XercesSingleton_H
