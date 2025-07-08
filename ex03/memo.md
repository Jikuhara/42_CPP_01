# CPP01
## ex03
### Unnecessary violence
WeaponクラスとHumanA、HumanBクラスを実装する。
Main関数では、HumanAとHumanBのインスタンスを作成し、攻撃を行う。
↑Mainはまあほぼテスト。

### Weaponクラス
作るものは3つ。
- プライベート属性: `std::string type`
- `getType()`: typeへの定数参照を返す
- `setType()`: typeを新しい値で設定
→Constant referrenceってなんやろ～。
setType()は、仮引数追加して良いのか？
しないと無理そうではある。
んで、referrenceで渡すのか、値渡しなのか。

### HumanAクラス と HumanBクラス の共通点
- Weaponを持つ。
- nameを持つ。
- attack()メソッドを持つ。
	- `<name> attacks with their <weapon type>`と出力する。
#### HumanA クラス と HumanB クラス の違い
- HumanAはWeaponをコンストラクタで受け取る。
- HumanBはWeaponをコンストラクタで受け取らない。
	- そのため、HumanBは武器を持たない場合があるが、HumanAは常に武器を持つ。

### やること
1. Weaponクラスを実装
	1. `getType()`メソッドを実装
	2. `setType()`メソッドを実装
2. HumanAクラスを実装
	1. コンストラクタでWeaponを受け取る
	2. `attack()`メソッドを実装
3. HumanBクラスを実装
	1. コンストラクタでWeaponを受け取らない→そもそもコンストラクタいらなそう。
	2. `attack()`メソッドを実装

定数参照がわかんね～～。
const std::string& なのか、
std::string const& なのか。
どっちでも良いのか？

[C++の基礎:関数のconst参照について学ぶ](https://docwiki.embarcadero.com/Support/ja/C%2B%2B%E3%81%AE%E5%9F%BA%E7%A4%8E:%E9%96%A2%E6%95%B0%E3%81%AEconst%E5%8F%82%E7%85%A7%E3%81%AB%E3%81%A4%E3%81%84%E3%81%A6%E5%AD%A6%E3%81%B6)
めっちゃ分かりやすいこれ。

const std::string&っぽい。
差異はあるのか？？
ってか、これ差異無さそうちゃう？
std::string& constはありそうで無い。
→そもそも再代入が禁止されているかららしい。
→確かに、再代入したらどこに代入するか分からんしなぁ。
→うーん、けど微妙に負に落ちない。まあいっか。

理解度少し上がった。
### メンバー関数にconstをつける
メンバー関数にconstをつけると、オブジェクトの状態を変更しないことを示す。
これにより、constオブジェクトからも呼び出すことができる。
例えば、`getType()`メソッドはオブジェクトの状態を変更しないため、constメンバー関数として定義することができる。

### const Weapon* smoething, Weapon* const somethingの違い。
- `const Weapon* something`: ポインタが指すWeaponオブジェクトは変更不可。ポインタ自体は変更可能。
- `Weapon* const something`: ポインタ自体は変更不可。ポインタが指すWeaponオブジェクトは変更可能。

ってことは、
- `const Weapon* const something`: ポインタが指すWeaponオブジェクトは変更不可。ポインタ自体も変更不可。


基本全部参照渡しで良い気がしてきた。
コピーするのってたしかにまじで無駄やしなぁ。

### 宣言時に、std::string tとするのと、std::string& とすることの違いは？
これって型的には同じやから、違い無さそう。
あーけど、参照は他のオブジェクトに依存してしまうという点で独立性が失われてて良くないな。

