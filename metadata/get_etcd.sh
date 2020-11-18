ETCD_VER=v
GITHUB_URL=https://github.com/etcd-io/etcd/releases/download
DOWNLOAD_URL=${GITHUB_URL}

wget ${DOWNLOAD_URL}/${ETCD_VER}/etcd-${ETCD_VER}-linux-amd64.tar.gz
tar -zxvf ./etcd-v3.4.2-linux-amd64.tar.gz
mkdir /usr/local/etcd
cp ./etcd-v3.4.2-linux-amd64/etcd* /usr/local/etcd
# 可能需要添加/usr/local/etcd到环境变量
sudo vi /etc/profile
export PATH=$PATH:/usr/local/etcd
source /etc/profile
