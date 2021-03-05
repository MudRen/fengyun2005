inherit ROOM;
void create()
{
        set("short", "老鼠洞");
        set("long", @LONG
这是一个黑漆漆的深洞，伸手不见五指，一股腐臭的味道扑鼻而来。洞很小，
勉强可以伸展开四肢，略一抬头，便会碰地撞到顶壁。明明刚才还在阳光明媚的
镖局大院，怎么一晃会到了这个鬼地方？
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
		  "down" : __DIR__"mice_room1",
	]));
        set("item_desc",([
        	"down":	"洞下面黑咕隆咚什么也看不清，只有些悉悉索索的动静。\n",
        ]));
        

	set("coor/x",200);
	set("coor/y",-60);
	set("coor/z",-5);
	setup();
}
