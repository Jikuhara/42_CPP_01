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
![発見した]({AB713994-8EC9-49AC-B495-E1F0580731D8}.png)
長すぎて読む気にならん。

```cpp
  enum _Ios_Openmode 
    { 
      _S_app 		= 1L << 0,
      _S_ate 		= 1L << 1,
      _S_bin 		= 1L << 2,
      _S_in 		= 1L << 3,
      _S_out 		= 1L << 4,
      _S_trunc 		= 1L << 5,
      _S_noreplace 	= 1L << 6,
      _S_ios_openmode_end = 1L << 16,
      _S_ios_openmode_max = __INT_MAX__,
      _S_ios_openmode_min = ~__INT_MAX__
    };
```
ぽいやつ発見。
多分、ios_base::inとかios_base::outとかは、普通に数字。マクロなのかな。
```cpp
    /// Open for input.  Default for @c ifstream and fstream.
    static const openmode in =		_S_in;
```
これでしょ！！！

openはこれぐらいで良さそう。
まあ返り値はまた今度調べよ。

### 読み取り
次は読み取り調べたい。
どうやってOpenしたやつを呼び出すのか。
```cpp
    fs << a << " " << b << " " << c << std::endl;
```
[引用元：これの例](https://cpprefjp.github.io/reference/fstream/basic_fstream.html)
めっちゃ簡単やん！！
たしかに、Write関数とかCPPでなかったしなぁ。
これの逆で読み取り行けそう。

これで書き込み読み取りは両方できそう。

あとは新しいファイルをどうやって作るか、か。

### ファイルの作成
どうせfstreamにありそう。調べる。
わかんね、関数は無い。

```cpp
#include <fstream>
#include <iostream>
#include <string>

int main() {
  // example.txtファイルを読み取り専用で開く
  std::ifstream ifs("example.txt");
  if (!ifs.is_open()) {
    std::cerr << "ファイルを開けませんでした" << std::endl;
    return 1;
  }

  // ファイルの内容を1行ずつ読み取り、出力する
  std::string line;
  while (std::getline(ifs, line)) {
    std::cout << line << std::endl;
  }

  // ファイルを閉じる (デストラクタでも自動的に閉じられる)
  ifs.close();
}
```
[引用元：これの例](https://cpprefjp.github.io/reference/fstream/basic_ifstream.html)

これデストラクタのお陰でクローズせんでええんか。激アツやん。
型宣言時にいきなり引数に代入で初期化できるのもすごい。

```cpp
	std::fstream s2;
	s2.open("not_exist_file_name", std::ios_base::out);
```
これで作れるらしい。
すげえええ。

後は気合で行けそう～～。

### 出力
```cpp
    // ファイルの先頭に戻る
    s1.seekg(0, std::ios::beg);
    
    // ファイルの内容を読み取って出力
    std::string line;
    std::cout << "=== ファイルの内容 ===" << std::endl;
    while (std::getline(s1, line)) {
        std::cout << line << std::endl;
    }
    
    s1.close();
```
引用元：ChatGPT
これでいけるらしい。なるほどね～～。一回Getlineで読み取って、出力するのか。

---
## 課題
手順をまとめよう。
openでファイルを開く。読み取り専用。
<filename>.replaceというファイルを作成。
getlineを使用して、読み取り専用で開いたファイルの内容を1行ずつ読み取る。→行またいだときやばくね？？
→全部くっつけてから処理すればいいんか？？
getlineで読み取った内容を置換する。→strcmpがあればいけそ。
新しいファイルに書き込む。

これで行けそう。
問題点は、でっかいファイルのときかなぁ。
１行ずつすれば行けそうやけど。→置換対象がデカ文字列のときに破綻しそう。行マタギもむずいし。

まあ全部読み取った後に、１個の文字列にして、置換実行が一番まるいか。
Inputのファイルサイズ書いてないの不親切すぎんか。。。

てか全部くっつけるならわざわざgetline使わんでも良さそう。
他のやり方無いんかなぁ。
とりあえずバカデカファイルのときは考えずに作るか。

これ改行どうやって捉えたら良いんやろ。
改行マタギは別の文字なんかな。sedの再実装的な課題やからsedの挙動に合わせるでええか。
```shell
kei2003730@JikuPC ~/A/c/4/ex04 (main)> sed 's/world/super/g' test.txt
Hello super
Hello wor
ld
testtesttest
```

```txt
Hello world
Hello wor
ld
testtesttest
```
こんな感じで置換される。
改行は無視して、置換対象の文字列があったら置換する感じか。
これめっちゃありがたいな～～～！


よしあとは、置換機構を作るだけやな。
std::stringを漁ろう。

### 置換機構
std::stringのメンバ関数に、findがあるからそれ使えば行けそう。
[参考元：cpprefjpの文字列色々](https://cpprefjp.github.io/reference/string/basic_string.html)
findの返り値気になる。
とりあえず、１行に対して、
前＋置換対象＋後 → 前＋置換後文字列＋後
に変換すれば行けそう。
stringってサイズ上限ないんかな。
置換後文字列に置換対象が入ってると無限ループしそうやなこれ。
「後」だけを、次回の入力にすればいいんかな。

[Findに関して](https://cpprefjp.github.io/reference/string/basic_string/find.html)
これの例が結構いい感じ。
posを返すのね～。

Ncopy欲しい。探そ。
[Copyに関して](https://cpprefjp.github.io/reference/string/basic_string/copy.html)
普通に引数にN突っ込んだらできるんや～。
copyがchar *しか扱えへんくてメチャ面倒。
なんとかならんかな。
char *からstringに変換して、appendするのが良いんかな。
