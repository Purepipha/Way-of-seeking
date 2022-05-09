template <typename T> struct Half//函数对象：减半一个T类对象
{ virtual void operator()(T & e) { e /= 2; }};//假设T可减半