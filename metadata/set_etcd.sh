TOKEN=token-01
CLUSTER_STATE=new
NAME_1=s1
NAME_2=s2
NAME_3=s3
NAME_4=s4
HOST_1=10.46.122.10
HOST_2=10.46.219.70
HOST_3=10.47.201.61
HOST_4=10.47.201.61
CLUSTER=${NAME_1}=http://${HOST_1}:2380,${NAME_2}=http://${HOST_2}:2380,${NAME_3}=http://${HOST_3}:2380,${NAME_4}=http://${HOST_4}:22380

{{"10.46.182.82","50051","2379","3306"},
                    {"10.47.201.61","50051","2379","3306"},
                    {"10.46.219.70","50051","2379","3306"},
                    {"10.46.219.70","50052","22379","33306"}

# For machine 1
THIS_NAME=${NAME_1}
THIS_IP=${HOST_1}
etcd --data-dir=data.etcd --name ${THIS_NAME} \
    --initial-advertise-peer-urls http://${THIS_IP}:2380 --listen-peer-urls http://${THIS_IP}:2380 \
    --advertise-client-urls http://${THIS_IP}:2379 --listen-client-urls http://${THIS_IP}:2379 \
    --initial-cluster ${CLUSTER} \
    --initial-cluster-state ${CLUSTER_STATE} --initial-cluster-token ${TOKEN}

# For machine 2
THIS_NAME=${NAME_2}
THIS_IP=${HOST_2}
etcd --data-dir=data.etcd --name ${THIS_NAME} \
    --initial-advertise-peer-urls http://${THIS_IP}:2380 --listen-peer-urls http://${THIS_IP}:2380 \
    --advertise-client-urls http://${THIS_IP}:2379 --listen-client-urls http://${THIS_IP}:2379 \
    --initial-cluster ${CLUSTER} \
    --initial-cluster-state ${CLUSTER_STATE} --initial-cluster-token ${TOKEN}

# For machine 3
THIS_NAME=${NAME_3}
THIS_IP=${HOST_3}
etcd --data-dir=data.etcd --name ${THIS_NAME} \
    --initial-advertise-peer-urls http://${THIS_IP}:2380 --listen-peer-urls http://${THIS_IP}:2380 \
    --advertise-client-urls http://${THIS_IP}:2379 --listen-client-urls http://${THIS_IP}:2379 \
    --initial-cluster ${CLUSTER} \
    --initial-cluster-state ${CLUSTER_STATE} --initial-cluster-token ${TOKEN}


# For machine 3
THIS_NAME=${NAME_4}
THIS_IP=${HOST_4}
etcd --data-dir=data.etcd --name ${THIS_NAME} \
    --initial-advertise-peer-urls http://${THIS_IP}:22380 --listen-peer-urls http://${THIS_IP}:22380 \
    --advertise-client-urls http://${THIS_IP}:22379 --listen-client-urls http://${THIS_IP}:22379 \
    --initial-cluster ${CLUSTER} \
    --initial-cluster-state ${CLUSTER_STATE} --initial-cluster-token ${TOKEN}


# 访问
HOST_1=10.77.70.190
HOST_2=10.77.70.191
HOST_3=10.77.70.192
HOST_4=10.77.70.192

HOST_1=10.46.182.82
HOST_2=10.46.235.16
HOST_3=10.46.219.70
HOST_4=10.46.219.70
ENDPOINTS=$HOST_1:2379,$HOST_2:2379,$HOST_3:2379,$HOST_4:22379

# 重启
CLUSTER_STATE=existing

# 同样执行上面的语句


# 访问示例
etcdctl --endpoints=10.77.70.192:2379 get /part_site/publisher.1