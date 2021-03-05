//Sinny@fengyun
//All Rights Reserved
inherit ROOM;
void create()
{
    set("short", "白云岛入口");
    set("long", @long
你极目远望，发觉白云岛宽广十数里，中心地带林木参天，宛若原始森林。山中
凸案处，但见琼楼玉宇，神秘古香，远远瞧来又似人间仙境。或见云雾飞来，掩埋岛
案，更显仙气十足。小岛东面怪石嶙峋，海浪拍击，乱石崩云，惊涛裂岸。西面却是
百花争艳，绿草覆地，煞是好看，更因岛上终年白云缭绕，所以世人谓之白云岛。
long
    );
    set("exits", 
      ([ 
	"southwest" : __DIR__"flowerroad2",
	"southeast" : __DIR__"pailangya",
	"north" : __DIR__"huangsha1",
      ]));
    set("objects", 
      ([ 
	__DIR__"npc/xiu1" : 1,
	__DIR__"npc/xiu2" : 1,
	__DIR__"obj/grass": 1,
      ]));
    set("outdoors", "baiyun");
    set("coor/x",0);
    set("coor/y",-20);
    set("coor/z",0);
    setup();
    replace_program(ROOM);
}
