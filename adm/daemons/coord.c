// /adm/daemons/coord.c
// written by akuma for fy4
// version 1.0
// first on 2002-9-20
//	Modified by Silencer on 2003-3, add ratio : 
//	"r" = 1 (if not defined) or query(domain+"/r")


inherit F_SAVE;
inherit F_DBASE;

string query_save_file();

int query_coor(string domain,string xyz);

void create()
{
	restore();
/*	if( !restore() && !mapp(coors) )
		coors = ([]);*/
}

string query_save_file()
{	
	return(DATA_DIR+"coord");// god knows what is that.
}

int query_coor(string domain,string xyz)
{
	if(!stringp(domain) || domain=="") return 0;
	if(!stringp(xyz) || xyz=="") return 0;
	if(!mapp(query(domain))) return 0;
	return query(domain+"/" +xyz);
	
}

int set_coor(string domain,int x,int y,int z)
{
	set(domain+"/"+"x",x);
	set(domain+"/"+"y",y);
	set(domain+"/"+"z",z);
	save();
}


int query_ratio(string domain)
{
	if(!stringp(domain) || domain=="") return 1;
	if(!mapp(query(domain)) || !query(domain+"/r"))	
		return 1;
	return query(domain+"/r");
}