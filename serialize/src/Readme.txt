



CDataStream ssTx(SER_NETWORK, serializeFlags);
ssTx << tx;


	template<typename T>
CDataStream& operator<<(const T& obj)
{

	::Serialize(*this, obj);
	return (*this);
}

	template<typename Stream, typename T>
inline void Serialize(Stream& os, const T& a)
{
	a.Serialize(os);
}

class COutPoint

template<typename Stream> void Serialize(Stream& s) const
{ 
	NCONST_PTR(this)->SerializationOp(s, CSerActionSerialize()); 
} 
template<typename Stream> void Unserialize(Stream& s) 
{ 
	SerializationOp(s, CSerActionUnserialize()); 
};

-- 然后
inline void SerializationOp(Stream& s, Operation ser_action) {
	(::SerReadWriteMany(s, ser_action, n));
}


template<typename Stream, typename... Args>
inline void SerReadWriteMany(Stream& s, CSerActionSerialize ser_action, const Args&... args)
{
    ::SerializeMany(s, args...);
}



template<typename Stream, typename Arg, typename... Args>
void SerializeMany(Stream& s, const Arg& arg, const Args&... args)
{
    ::Serialize(s, arg);
    ::SerializeMany(s, args...);
}


template<typename Stream> inline void Serialize(Stream& s, char a ) { ser_writedata8(s, a); }
template<typename Stream> inline void Serialize(Stream& s, int8_t a ) { ser_writedata8(s, a); }
template<typename Stream> inline void Serialize(Stream& s, uint8_t a ) { ser_writedata8(s, a); }
template<typename Stream> inline void Serialize(Stream& s, int16_t a ) { ser_writedata16(s, a); }
template<typename Stream> inline void Serialize(Stream& s, uint16_t a) { ser_writedata16(s, a); }
template<typename Stream> inline void Serialize(Stream& s, int32_t a ) { ser_writedata32(s, a); }
template<typename Stream> inline void Serialize(Stream& s, uint32_t a) { ser_writedata32(s, a); }
template<typename Stream> inline void Serialize(Stream& s, int64_t a ) { ser_writedata64(s, a); }
template<typename Stream> inline void Serialize(Stream& s, uint64_t a) { ser_writedata64(s, a); }
template<typename Stream> inline void Serialize(Stream& s, float a ) { ser_writedata32(s, ser_float_to_uint32(a)); }
template<typename Stream> inline void Serialize(Stream& s, double a ) { ser_writedata64(s, ser_double_to_uint64(a)); }



