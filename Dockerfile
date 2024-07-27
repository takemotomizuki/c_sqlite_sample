FROM ubuntu:20.04

WORKDIR /

RUN apt-get update

# タイムゾーンの設定
RUN apt install -y tzdata
ENV TZ=Asia/Tokyo

# 開発環境のシステムインストール
RUN apt install -y gcc cmake git sqlite3 libsqlite3-dev