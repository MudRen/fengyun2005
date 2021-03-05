// virtuald.c
// Modified by Find.
/* /system/daemon/virtual.c
 * from XO Object Library II
 * compile some virtual objects. 
 * created by trill 19970920
 * last modify by akuma on 24-04-2002
 * version 1.1 for player self-found domains
 * add virtual object for MF by akuma 2003-7-9
 */


void create()
{
	seteuid(getuid());
}

// This function is called by master object to return the "virtual" object
// of <file> when dirver failed to find such a file.

object compile_object(string file)
{

	string pname = file;
	object obj,oe;
	if ( !file )
	{
		return 0;
	}
	else if (strlen(file) > 15 && file[0..15] == "/d/phoenix/base/" && file != "/d/phoenix/base/alive")
	{

		obj = find_object("/d/phoenix/base/alive");
		if (!obj)
			obj = load_object("/d/phoenix/base/alive");
		// this object controls the whole virtual area.

		oe = obj->get_obj(file);
		if (oe)
			return oe;
		destruct(obj);
		return 0;
	}	
	else if ( strlen(file) > 15 && file[0..15] == "/d/place/player/" )
	{
		object room = new ("/d/place/player/newroom");
		if (room->restore_me(file[16..]))
			return room;
		else
		{
			destruct(room);
			return 0;
		}
	}
	else if ( strlen(file) > 15 && file[0..15] == "/d/place/domain/" )
	{		
		object room = new ("/std/room/vroom");                
		room->restore_me(file[16..]);
		room->set_exits(file);
		return room;
	}

	else if (strlen(file)>3 && file[0..3] == "/vo/")
	{	
		string* str1;			
		object newob;
		//用explode来区分出/vo/cloth/xxxxx
		//把type找出来然后load一个基本type，然后去restore那个.o
		
		str1=explode(file,"/");
		newob =new ("/std/vobase/"+str1[1]);
		//这里我们只能替代一下，因为现在这个东西在return以前还不是vo所以直接restore不对
		newob->restore_me(sprintf(DATA_DIR "vo/%s/%s",str1[1],str1[2]));		
		return newob;		
		//return (new ("/std/vobase/basic"));
	}
			
	while (1)
	{
		int idx = strsrch(pname, "/", -1);
			
		if(idx == -1)
			return 0;

		if( idx != 0 )
			pname = pname[0..idx-1];
		
//		CHANNEL_D->do_sys_channel("sys", "file= " + file + "  pname=" + pname);
		
		if(file_size(pname + ".c") >= 0)
			if(obj = pname->query_maze_room(file[idx+1..]))
			{
				obj->set_virtual_flag();
				return obj;
			}
		if(!idx)
			return 0;
	}

	return 0;
}
