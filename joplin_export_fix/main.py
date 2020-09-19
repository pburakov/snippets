import json
import os
from datetime import datetime

# This tool adjust creation timestamp for Joplin notes on macOS

source = "export"  # Joplin export dir
target = "target"  # target .md notes

for name in os.listdir(source):
    try:
        source_file = open(source + '/' + name)
        source_dict = json.loads(source_file.read())
        creation_time = datetime.fromtimestamp(source_dict["user_created_time"] / 1000)
        title = source_dict["title"]
        dest_file = open(target + '/' + title + ".md").name
        ts = creation_time.strftime("%Y%m%d%H%M.%S")
        print("setting", dest_file, ts)
        os.system("touch -mt {} '{}'".format(ts, dest_file))
    except KeyError as e:
        pass
    except IsADirectoryError as e:
        pass
    except FileNotFoundError as e:
        print("\tno file", e)
    except UnicodeDecodeError as e:
        print("\tcould not read", title)
