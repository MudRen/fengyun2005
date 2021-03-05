// Ascii mice from http://www.geocities.com/SouthBeach/Marina/4942/ascii.htm


inherit ROOM;
void create()
{
        set("short", "老鼠洞");
        set("long", @LONG
    
[37m     
               _                       __
              /   \                  /      \
             '      \              /          \
            |       |Oo          o|            |
            `    \  |OOOo......oOO|   /        |
             `    \\OOOOOOOOOOOOOOO\//        /
               \ _o\OOOOOOOOOOOOOOOO//. ___ /
           ______OOOOOOOOOOOOOOOOOOOOOOOo.___
            --- OO'* `OOOOOOOOOO'*  `OOOOO--
                OO.   OOOOOOOOO'    .OOOOO o
                `OOOooOOOOOOOOOooooOOOOOO'OOOo
              .OO "OOOOOOOOOOOOOOOOOOOO"OOOOOOOo
          __ OOOOOO`OOOOOOOOOOOOOOOO"OOOOOOOOOOOOo
         ___OOOOOOOO_"OOOOOOOOOOO"_OOOOOOOOOOOOOOOO
           OOOOO^OOOO0`(____)/"OOOOOOOOOOOOO^OOOOOO
           OOOOO OO000/00||00\000000OOOOOOOO OOOOOO
           OOOOO O0000000000000000 ppppoooooOOOOOO
           `OOOOO 0000000000000000 QQQQ "OOOOOOO"
            o"OOOO 000000000000000oooooOOoooooooO'
            OOo"OOOO.00000000000000000000OOOOOOOO'
           OOOOOO QQQQ 0000000000000000000OOOOOOO
          OOOOOO00eeee00000000000000000000OOOOOOOO.
         OOOOOOOO000000000000000000000000OOOOOOOOOO
         OOOOOOOOO00000000000000000000000OOOOOOOOOO
         `OOOOOOOOO000000000000000000000OOOOOOOOOOO
           "OOOOOOOO0000000000000000000OOOOOOOOOOO'
             "OOOOOOO00000000000000000OOOOOOOOOO"
  .ooooOOOOOOOo"OOOOOOO000000000000OOOOOOOOOOO"
.OOO"""""""""".oOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
OOO         QQQQO"'                     `"QQQQ
OOO
`OOo.
  `"OOOOOOOOOOOOoooooooo....

[0m

LONG
        );
        set("exits", ([ /* sizeof() == 4 */
		  "down" : __DIR__"secret_room",
	]));
        set("item_desc",([
        	"down":	"洞下面黑咕隆咚什么也看不清，只有些悉悉索索的动静。\n",
        ]));
        
        set("objects", ([
        	__DIR__"npc/b_mice" : 1,
         ]) );

	set("coor/x",200);
	set("coor/y",-60);
	set("coor/z",-20);
	setup();
}

int valid_leave(object me, string arg){
	object roach;
	
	if (arg == "down") {
		if (roach = present("mouse",this_object()))
			return notify_fail(roach->name()+"恶狠狠地扑了上来。\n");
		else
			message_vision("$N匍匐在地上向下钻去。。。。\n",me);
			tell_object(me,"扑通一声，你从老鼠洞里掉了出来。\n\n\n");
			return 1;
	}
	return ::valid_leave(me,arg);
}
