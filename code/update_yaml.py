import sys
import yaml

# 从命令行参数获取要更新的文件名和状态值
FILE = sys.argv[1]
JOB_ID = sys.argv[2]
NEW_RESULT = sys.argv[3]

# 读取YAML文件
with open(FILE, 'r') as stream:
    try:
        data = yaml.safe_load(stream)
    except yaml.YAMLError as exc:
        print(exc)

# 查找指定job_id对应的数据，并更新result值
for key, item in data['metadata']['jobs'].items():
    if key == JOB_ID:
        item['result'] = NEW_RESULT

# 将更新后的数据写回YAML文件
with open(FILE, 'w') as outfile:
    yaml.dump(data, outfile, default_flow_style=False)

#python update_yaml.py config.yaml zte.wireless.ccn.ccsp.productci.oam.smf.upgrade failed