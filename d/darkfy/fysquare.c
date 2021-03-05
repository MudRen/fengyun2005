inherit ROOM;
void create()
{
        set("short", "风云广场");
        set("long", @LONG
抬头望去，许多早已过去的回忆扑面而来，这里竟然还和当年一样，广场的中央
是方园约十丈的水池，池中的金鱼还在悠闲的漫游。金色的鱼鳞与碧绿的浮萍相互辉
映，依旧赏心悦目。池水的中央的石柱上的九头龙仍然还在守望四方。每当雨天，潺
潺雨珠涓涓涌出龙首，汇成的旋律依稀如昨，如情人之泪，落断情肠。物是人非，当
年风华少年，所铭记的青春，理想，爱恨情仇。如今却都还在麽？那些曾经说着永不
分离的人儿，是否已经都散落在天涯了呢？
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"nwind1",
  "south" : __DIR__"swind1",
  "east" : __DIR__"ecloud1",
  "west" : __DIR__"wcloud1",
  	"down":	__DIR__"prep",
]));
        set("outdoors", "fengyun");
        set("resource/water",1);
        set("liquid/name","碧绿的水");
        set("liquid/type", "alcohol");
        set("liquid/drunk_apply",3);
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",-300);
        setup();
        // To "load" the board, don't ever "clone" a bulletin board.
        call_other( "/obj/board/fysquare_b", "???" );

}

void init()
{
        add_action("do_fillwater", "fillwater");
}
int do_fillwater(string arg)
{
        object *list, ob;
        int i, can_fillwater;
        string dir;

        if( !arg || arg=="" ) return 0;

        if( arg=="skin" || arg=="wineskin" ) {
                list = all_inventory(this_player());
                i = sizeof(list);
                can_fillwater = 0;
                while (i--) {
                  if (((string)list[i]->query("liquid/type") == "alcohol")
 || ((string)list[i]->query("liquid/type") == "water")         ) {
                        ob = list[i];
                        can_fillwater = 1;
                        ob->set("liquid", ([
                                "type": "water",
                                "name": "清水",
                                "remaining": 15,
                                "drunk_apply": 6,
                        ]) );
                        write("你从水池里装满了清水！ \n");
                        return 1;
                   }
                }
                if (can_fillwater ==0) {
                        write("你没有装水的东西啊....\n");
                        return 1;
                }
        }
        else {
                write("你要往什么东西里灌水？\n");
        }
        return 1;
}

