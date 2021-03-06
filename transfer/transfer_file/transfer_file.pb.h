// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: transfer_file.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_transfer_5ffile_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_transfer_5ffile_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3013000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3013000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_transfer_5ffile_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_transfer_5ffile_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_transfer_5ffile_2eproto;
namespace transferfile {
class Chunk;
class ChunkDefaultTypeInternal;
extern ChunkDefaultTypeInternal _Chunk_default_instance_;
class Reply;
class ReplyDefaultTypeInternal;
extern ReplyDefaultTypeInternal _Reply_default_instance_;
}  // namespace transferfile
PROTOBUF_NAMESPACE_OPEN
template<> ::transferfile::Chunk* Arena::CreateMaybeMessage<::transferfile::Chunk>(Arena*);
template<> ::transferfile::Reply* Arena::CreateMaybeMessage<::transferfile::Reply>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace transferfile {

// ===================================================================

class Chunk PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:transferfile.Chunk) */ {
 public:
  inline Chunk() : Chunk(nullptr) {}
  virtual ~Chunk();

  Chunk(const Chunk& from);
  Chunk(Chunk&& from) noexcept
    : Chunk() {
    *this = ::std::move(from);
  }

  inline Chunk& operator=(const Chunk& from) {
    CopyFrom(from);
    return *this;
  }
  inline Chunk& operator=(Chunk&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const Chunk& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Chunk* internal_default_instance() {
    return reinterpret_cast<const Chunk*>(
               &_Chunk_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Chunk& a, Chunk& b) {
    a.Swap(&b);
  }
  inline void Swap(Chunk* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Chunk* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Chunk* New() const final {
    return CreateMaybeMessage<Chunk>(nullptr);
  }

  Chunk* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Chunk>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Chunk& from);
  void MergeFrom(const Chunk& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Chunk* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "transferfile.Chunk";
  }
  protected:
  explicit Chunk(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_transfer_5ffile_2eproto);
    return ::descriptor_table_transfer_5ffile_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kBufferFieldNumber = 1,
  };
  // bytes buffer = 1;
  void clear_buffer();
  const std::string& buffer() const;
  void set_buffer(const std::string& value);
  void set_buffer(std::string&& value);
  void set_buffer(const char* value);
  void set_buffer(const void* value, size_t size);
  std::string* mutable_buffer();
  std::string* release_buffer();
  void set_allocated_buffer(std::string* buffer);
  private:
  const std::string& _internal_buffer() const;
  void _internal_set_buffer(const std::string& value);
  std::string* _internal_mutable_buffer();
  public:

  // @@protoc_insertion_point(class_scope:transferfile.Chunk)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr buffer_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_transfer_5ffile_2eproto;
};
// -------------------------------------------------------------------

class Reply PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:transferfile.Reply) */ {
 public:
  inline Reply() : Reply(nullptr) {}
  virtual ~Reply();

  Reply(const Reply& from);
  Reply(Reply&& from) noexcept
    : Reply() {
    *this = ::std::move(from);
  }

  inline Reply& operator=(const Reply& from) {
    CopyFrom(from);
    return *this;
  }
  inline Reply& operator=(Reply&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const Reply& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Reply* internal_default_instance() {
    return reinterpret_cast<const Reply*>(
               &_Reply_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Reply& a, Reply& b) {
    a.Swap(&b);
  }
  inline void Swap(Reply* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Reply* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Reply* New() const final {
    return CreateMaybeMessage<Reply>(nullptr);
  }

  Reply* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Reply>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Reply& from);
  void MergeFrom(const Reply& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Reply* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "transferfile.Reply";
  }
  protected:
  explicit Reply(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_transfer_5ffile_2eproto);
    return ::descriptor_table_transfer_5ffile_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kLengthFieldNumber = 1,
  };
  // int32 length = 1;
  void clear_length();
  ::PROTOBUF_NAMESPACE_ID::int32 length() const;
  void set_length(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_length() const;
  void _internal_set_length(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:transferfile.Reply)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::int32 length_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_transfer_5ffile_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Chunk

// bytes buffer = 1;
inline void Chunk::clear_buffer() {
  buffer_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& Chunk::buffer() const {
  // @@protoc_insertion_point(field_get:transferfile.Chunk.buffer)
  return _internal_buffer();
}
inline void Chunk::set_buffer(const std::string& value) {
  _internal_set_buffer(value);
  // @@protoc_insertion_point(field_set:transferfile.Chunk.buffer)
}
inline std::string* Chunk::mutable_buffer() {
  // @@protoc_insertion_point(field_mutable:transferfile.Chunk.buffer)
  return _internal_mutable_buffer();
}
inline const std::string& Chunk::_internal_buffer() const {
  return buffer_.Get();
}
inline void Chunk::_internal_set_buffer(const std::string& value) {
  
  buffer_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void Chunk::set_buffer(std::string&& value) {
  
  buffer_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:transferfile.Chunk.buffer)
}
inline void Chunk::set_buffer(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  buffer_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:transferfile.Chunk.buffer)
}
inline void Chunk::set_buffer(const void* value,
    size_t size) {
  
  buffer_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:transferfile.Chunk.buffer)
}
inline std::string* Chunk::_internal_mutable_buffer() {
  
  return buffer_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* Chunk::release_buffer() {
  // @@protoc_insertion_point(field_release:transferfile.Chunk.buffer)
  return buffer_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void Chunk::set_allocated_buffer(std::string* buffer) {
  if (buffer != nullptr) {
    
  } else {
    
  }
  buffer_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), buffer,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:transferfile.Chunk.buffer)
}

// -------------------------------------------------------------------

// Reply

// int32 length = 1;
inline void Reply::clear_length() {
  length_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Reply::_internal_length() const {
  return length_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Reply::length() const {
  // @@protoc_insertion_point(field_get:transferfile.Reply.length)
  return _internal_length();
}
inline void Reply::_internal_set_length(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  length_ = value;
}
inline void Reply::set_length(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_length(value);
  // @@protoc_insertion_point(field_set:transferfile.Reply.length)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace transferfile

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_transfer_5ffile_2eproto
