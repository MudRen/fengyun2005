#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "会客厅");
    set("long", @LONG
四下的灯散发着柔和的光，红木长台的周围放了几个椅子。整个房间的布置是
那么的和谐，你真的想敞开你的心扉，痛痛快快地将所有的实情和大家分享。往南
是休息室。
LONG
    );
    set("exits", ([ /* sizeof() == 1 */
	"south" : __DIR__"hall",
//	"north" : __DIR__"courthouse",
	"east"  : __DIR__"jail",
	"down"  : AREA_FY"fysquare",
	"up"  : __DIR__"demoroom",
      ]));
    set("coor/x",0);
    set("coor/y",0);
    set("coor/z",20);
    set("no_magic",1);
    set("no_fight",1);
    setup();
//    call_other("/obj/board/wizard_j", "???");

}
void init()
{
    
        add_action("do_jump", "jump");
}

int valid_leave(object who, string dir){
	
	if (dir == "east")
		return notify_fail("风云监狱，你进去干吗？\n");

	if (dir == "up" && !wizardp(who))
		return notify_fail("风云练功房，闲人莫入。\n");
	
	if (dir == "south" && !wizardp(who))
		return notify_fail("你不能进入巫师的办公室。\n");
	
	return ::valid_leave(who,dir);
}

int test3(){
	object ob;
	
	ob = find_living("silencer");
	write(sprintf("%O\n",ob));
	return 1;
}

int test4(){
	mapping x;
	x = ([ "a": 2, "b": 3, "c": 5 ]);
	map_delete(x,"a");
	write(sprintf("%O\n",x));
	return 1;
}
	
int test1(){

#ifdef NONENCRYPTED_WRITE

	object item;
	string *list,str,gender;
 	int i;
 	
	set("drop/common_drop",({
"/obj/generate/wrists_70_4.c",
"/obj/generate/surcoat_70_17.c",
"/obj/generate/neck_70_5.c",
"/obj/generate/neck_70_15.c",
"/obj/generate/head_70_15.c",
"/obj/generate/boots_70_16.c",
"/obj/generate/surcoat_70_5.c",
"/obj/generate/head_70_5.c",
"/obj/generate/cloth3_70_15.c",
"/obj/generate/cloth1_70_5.c",
"/obj/generate/boots_70_6.c",

	}) );
	
	set("drop/rare_drop",({
		"none",
	}) );
	
	list = query("drop/common_drop");
	for (i=0;i<sizeof(list);i++){
		item = new(list[i]);
		item->move(this_object());
		write((i+1)+": "+ item->query("name")+"("+list[i]+")  \n");
		
		gender = "不定";
		if (item->query("male_only")) gender = "男性";
		if (item->query("female_only")) gender = "女性";
			
		str = sprintf(YEL"(%s：才智 +%s 力量 +%s 定力 +%s 运气 +%s 速度 +%s 保护力 +%d 精 +%d 气 +%d 神 +%d )\n"NOR,
			gender,
			sprintf("%d.%d",item->query("armor_prop/intelligence")/10,item->query("armor_prop/intelligence")%10),
			sprintf("%d.%d",item->query("armor_prop/strength")/10,item->query("armor_prop/strength")%10),
			sprintf("%d.%d",item->query("armor_prop/composure")/10,item->query("armor_prop/composure")%10),
			sprintf("%d.%d",item->query("armor_prop/karma")/10,item->query("armor_prop/karma")%10),
			sprintf("%d.%d",item->query("armor_prop/agility")/10,item->query("armor_prop/agility")%10),
			item->query("armor_prop/armor"),
			item->query("armor_prop/max_gin"),
			item->query("armor_prop/max_kee"),
			item->query("armor_prop/max_sen"),
			);
			destruct(item);
		write(str);
	}
	
#endif
	return 1;
}
int do_jump(string arg)
{
        object room, me=this_player();
        if( !arg || arg != "up" ) return 0;

        room = get_object( "/adm/daemons/fairyland_quest/room_door_hj" );
        if( !room ) return 0;

        tell_room(environment(me),me->query("name")+"使劲地往上一跳，突然卷来一阵旋风，"+
                me->query("name")+"顿时被风刮得不知所踪。\n",me);

        write("你使劲地往上一跳，忽地平地卷起一阵旋风，恍惚中你已来到了「幻境」。\n");
        me->move(room);
        tell_room(room,"忽然一阵旋风袭过，"+me->query("name")+"已出现在这里。\n",me);
        return 1;
}

void test(){
//	string msg;
	
	write(crypt("战死",0));
	
	if (crypt("1972","Bj7mJPd4q6Pbk")== "Bj7mJPd4q6Pbk")
		write (" right \n");
	else
		write (" wrong\n");
	
}


void test2(string str){
//	object ob,*ob1;
	int i;
	
	i = sizeof(users());
	
	write ("user = " + i + "\n");
}