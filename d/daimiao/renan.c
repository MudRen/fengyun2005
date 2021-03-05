
#include <room.h>
inherit ROOM;
void create()
{
  set("short","仁安门");
  set("long",@LONG
仁安门，取自孔子“仁者安仁”之意。殿内原祭祀天聋、地哑之神，两侧是东
西门神。配天与仁安之门，由通道相连，前有铜狮蹲列，后有石狮守卫，进入此门
便可以看到万代瞻仰的天贶殿在远处雄伟的泰山的衬托之下，显得尤其壮观。
LONG
  );
  	set("exits",([
         	"north":__DIR__"gelaochi",
         	"south":__DIR__"peitian.c",
         	"east" :__DIR__"dongyu.c",
         	"west" :__DIR__"chuxun.c",
        ]));
        set("objects", ([
        	__DIR__"npc/guard3":	2,
        
       	]) );
	set("coor/x",0);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
  	replace_program(ROOM);
}
