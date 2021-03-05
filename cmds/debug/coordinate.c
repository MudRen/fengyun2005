#define SYNTAX	"syntax :coordinate x,y,z\n"
inherit F_CLEAN_UP;
int do_one_room(object room, int x, int y, int z);
int main(object me, string arg)
{
	int x,y,z;
        if(!me->query("env/yesiknow")) return notify_fail("这个指令已经被废除了！\n");
	if(sscanf(arg,"%d,%d,%d",x,y,z) != 3)	
	return notify_fail(SYNTAX);
	do_one_room(environment(me),x,y,z);
	return 1;
}

int do_one_room(object room, int x, int y, int z)
{
	mapping exits;
	string *directions;
	string dir;
	object nextroom;
	int j;
	if (room->query("coor")) return 1;
	reset_eval_cost();
	room->set("coor/x", x);
	room->set("coor/y", y);
	room->set("coor/z", z);
	write("Finished room "+ base_name(room) +"\n");
	exits = room->query("exits");
	if(!mapp(exits) || !sizeof(exits)) return 1;
	directions = keys(exits);
	for(j=0;j<sizeof(directions);j++)
	{
	x=(int) room->query("coor/x");
	y=(int) room->query("coor/y");
	z=(int) room->query("coor/z");
		dir = directions[j];
	                if(!objectp(nextroom=find_object(exits[dir])))
	                        nextroom=load_object(exits[dir]);
		switch(dir) {
		case "north" : y+=100;do_one_room(nextroom,x,y,z);break;
		case "south" : y-=100;do_one_room(nextroom,x,y,z);break;
		case "east" :  x+=100;do_one_room(nextroom,x,y,z);break;
		case "west" :  x-=100;do_one_room(nextroom,x,y,z);break;
		case "northup" : y+=100;z+=10;do_one_room(nextroom,x,y,z);break;
		case "southup" : y-=100;z+=10;do_one_room(nextroom,x,y,z);break;
		case "eastup" : x+=100;z+=10;do_one_room(nextroom,x,y,z);break;
		case "westup" : x-=100;z+=10;do_one_room(nextroom,x,y,z);break;
		case "northdown" : y+=100;z-=10;do_one_room(nextroom,x,y,z);break;
		case "southdown" : y-=100;z-=10;do_one_room(nextroom,x,y,z);break;
		case "eastdown":  x+=100;z-=10;do_one_room(nextroom,x,y,z);break;
		case "westdown": x-=100;z-=10;do_one_room(nextroom,x,y,z);break;
		case "northeast" : y+=100;x+=10;do_one_room(nextroom,x,y,z);break;
		case "northwest" : y+=100;x-=10;do_one_room(nextroom,x,y,z);break;
		case "southeast": y-=100;x+=10;do_one_room(nextroom,x,y,z);break;
		case "southwest": y-=100;x-=10;do_one_room(nextroom,x,y,z);break;
		case "up" : z+=10;do_one_room(nextroom,x,y,z);break;
		case "down" : z-=10;do_one_room(nextroom,x,y,z);break;
		}
}
return 1;
}
