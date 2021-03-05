// searoad.c
inherit ROOM;
void create()
{
        set("short", "平台");
        set("long", @LONG
上山数百丈，道旁一角小亭，绿石朱栏，玲珑可观。一人倚栏相候。前面是一
道长阶直达峰巅。
LONG
        );
        set("objects",([
        	AREA_TIEFLAG"npc/qinggirl1" : 2,
        ]) );
        set("exits", ([ 
	  	"west" : __DIR__"uproad3",
  		"eastup" : __DIR__"uproad4",
	]));
        set("outdoors", "tieflag");
	set("coor/x",80);
	set("coor/y",0);
	set("coor/z",20);
	setup();
}

/*

int valid_leave(object who,string dir)
{   
    object girl, mask;
    string gender;
    
    girl=present("sword girl",this_object());
    
    mask = present("skinmask", who);
	if (objectp(mask) && mask->query("equipped")) 
		gender = mask->query("fakegender");
	
	write ("gender is " + gender + "\n");	
    if(girl && living(girl) && userp(who) && dir == "eastup") {
		if ( (gender && gender == "男性")
				|| who->query("gender")=="男性")
   		{
   			message("vision",girl->name()+"说道：“这位公子请留步。”\n",this_object());
   			return notify_fail(""); 
   		}
   	}
   	return 1;
}
*/