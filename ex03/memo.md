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
	1. コンストラクタでWeaponを受け取らない
	2. `attack()`メソッドを実装
