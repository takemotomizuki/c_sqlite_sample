# Docker環境を使う

この環境はC言語とslite3でC言語からDBを操作する演習を行うことができます。 \
Dockerを起動するだけで実行環境を整えることができます。 \
以下、手順です。

## Docker Desktopのインストール

[Docker Desktopの公式サイト](https://www.docker.com/ja-jp/products/docker-desktop/)からアプリをインストールする。

## VSCodeにDev Containersをインストールする

![Dev Containerの画像](assets/devcontainer.png)

## 開く

左下の><ボタンを押し、コンテナーでフォルダを開くを選択
![><ボタンを押す](assets/remote.png)
このリポジトリのファイルを選択し、開く
![><ボタンを押す](assets/fileselect.png)

# sqliteについて

sqliteの対話モードを始める方法

```
cd database
sqlite3 データベース名
```

ここでsqlによるデータの追加や削除ができる。 \
cdしなくても実行自体はできるがファイルが生成される場所がカレントディレクトリになるので注意。

# サンプルについて

src下に、
```
placeholder.c
sample.c
```
というファイルを作成した。
一応サンプルなので、これを参考にしてもらえれば

## プレースホルダについて

src/placeholder.cに以下の行があるがsqlの一部が?となっている。
```
rc = sqlite3_prepare_v2(db,"SELECT id, name FROM tb_test WHERE id = ?", -1, &stmt, 0);
```
ここに、後から数値をバインドすることでsqlに安全に値を埋め込める。
```
//選択する行
int id = 1;
//バインド
sqlite3_bind_int(stmt, 1, id);
```