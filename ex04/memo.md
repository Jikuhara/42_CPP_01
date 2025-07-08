# CPP01
## ex04
### Sed is for losers
課題名おもろ。
3つパラメータ受け取る。
1つ目にfilename
2つ目に置換対象
3つ目に置換後

これをReplaceってやつ以外で実装。
ざっとやることは、
open的なのでファイルを開いて、
文字列コピーして、
置換して、
新たなファイルを作成して、
書き込む。

まず、C langのOpenに対応するC++用の関数を探す必要がある。
[ぽいやつ](https://cpprefjp.github.io/reference/fstream/basic_fstream/open.html)

ぽいやつを発見。
てか、manにCPP用のやつ無いんかな。
ChatGPTに聞いたら無さそうやった。
cppreference.com (日本語版: cpprefjp.github.io)
これが良さげらしい。
[cpprefjp.github.io](https://cpprefjp.github.io/index.html)
今みてるやつやん！！

iostreamとはfstreamとか、後ろのstreamって何なんやろ。文字列とかの流れ？？まとまり？
調べたけどよ－分からん。

とりあえず、fstreamにある、openを使用しよう。

次は、C langのReadに対応するやつを探そう。
fstreamにどうせありそう。

fstreamを見てみる。
```
  /// Class for @c char mixed input and output file streams.
  typedef basic_fstream<char> 		fstream;
```
定義。

Basic_fstreamを見てみる。
```cpp

  // [27.8.1.11] Template class basic_fstream
  /**
   *  @brief  Controlling input and output for files.
   *  @ingroup io
   *
   *  @tparam _CharT  Type of character stream.
   *  @tparam _Traits  Traits for character type, defaults to
   *                   char_traits<_CharT>.
   *
   *  This class supports reading from and writing to named files, using
   *  the inherited functions from std::basic_iostream.  To control the
   *  associated sequence, an instance of std::basic_filebuf is used, which
   *  this page refers to as @c sb.
   */
  template<typename _CharT, typename _Traits>
    class basic_fstream : public basic_iostream<_CharT, _Traits>
    {
    public:
      // Types:
      typedef _CharT 					char_type;
      typedef _Traits 					traits_type;
      typedef typename traits_type::int_type 		int_type;
      typedef typename traits_type::pos_type 		pos_type;
      typedef typename traits_type::off_type 		off_type;

      // Non-standard types:
      typedef basic_filebuf<char_type, traits_type> 	__filebuf_type;
      typedef basic_ios<char_type, traits_type>		__ios_type;
      typedef basic_iostream<char_type, traits_type>	__iostream_type;

    private:
      __filebuf_type	_M_filebuf;

    public:
      // Constructors/destructor:
      /**
       *  @brief  Default constructor.
       *
       *  Initializes @c sb using its default constructor, and passes
       *  @c &sb to the base class initializer.  Does not open any files
       *  (you haven't given it a filename to open).
       */
      basic_fstream()
      : __iostream_type(), _M_filebuf()
      { this->init(&_M_filebuf); }

      /**
       *  @brief  Create an input/output file stream.
       *  @param  __s  Null terminated string specifying the filename.
       *  @param  __mode  Open file in specified mode (see std::ios_base).
       */
      explicit
      basic_fstream(const char* __s,
		    ios_base::openmode __mode = ios_base::in | ios_base::out)
      : __iostream_type(0), _M_filebuf()
      {
	this->init(&_M_filebuf);
	this->open(__s, __mode);
      }
```
これっぽい。
クラスって便利やなぁ。
[例がいい感じ](https://cpprefjp.github.io/reference/fstream/basic_fstream.html)
ここに書いてある例が結構勉強になりそう。
Openに引数にmodeがある。まあ似たようなのC langにもあったしな、納得。
```cpp
      open(const char* __s,
	   ios_base::openmode __mode = ios_base::in | ios_base::out)
```
後ろの仮引数の書き方があんま意味分からん。なんやこの書き方。
ios_baseLLopenmode は型宣言。
__modeは変数名。
ios_base::in | ios_base::outは、ios_baseの中のinとoutをビット演算でORしている。
これが、openのmodeになる。

型を直接ぶち込んでビット演算してるのやばくね？？？
int | intみたいなことやろ？？

まあけど次調べるべきはios_baseクラスの中身か。
